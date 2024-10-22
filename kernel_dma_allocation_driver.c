#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/uaccess.h>
#include <linux/dma-mapping.h>
#include <linux/cdev.h>

#define DEVICE_NAME "dma_device"
#define DMA_BUFFER_SIZE (4096) // Size of the DMA buffer

static struct cdev my_cdev;
static dev_t dev_num;
static void *dma_buffer;        // Pointer to DMA buffer
static dma_addr_t dma_handle;   // Physical address for DMA

// mmap function to map the DMA buffer into user space
static int dma_mmap(struct file *filp, struct vm_area_struct *vma) {
    unsigned long size = vma->vm_end - vma->vm_start;

    if (size > DMA_BUFFER_SIZE) {
        return -EINVAL;
    }

    // Remap DMA buffer to user space
    if (remap_pfn_range(vma, vma->vm_start, virt_to_phys(dma_buffer) >> PAGE_SHIFT,
                        size, vma->vm_page_prot)) {
        return -EAGAIN;
    }

    return 0;
}

// File operations structure
static const struct file_operations dma_fops = {
    .owner = THIS_MODULE,
    .mmap = dma_mmap,
};

// Initialize the DMA buffer in the kernel driver
static int __init dma_init(void) {
    int result;

    // Allocate a character device number
    result = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
    if (result < 0) {
        printk(KERN_ERR "Failed to allocate character device number\n");
        return result;
    }

    // Initialize and add the character device
    cdev_init(&my_cdev, &dma_fops);
    result = cdev_add(&my_cdev, dev_num, 1);
    if (result < 0) {
        unregister_chrdev_region(dev_num, 1);
        printk(KERN_ERR "Failed to add character device\n");
        return result;
    }

    // Allocate coherent memory for DMA (physically contiguous and cache-coherent)
    dma_buffer = dma_alloc_coherent(NULL, DMA_BUFFER_SIZE, &dma_handle, GFP_KERNEL);
    if (!dma_buffer) {
        printk(KERN_ERR "Failed to allocate DMA buffer\n");
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev_num, 1);
        return -ENOMEM;
    }

    printk(KERN_INFO "DMA buffer allocated at virtual address %p (physical address %pad)\n",
           dma_buffer, &dma_handle);

    return 0;
}

// Cleanup the DMA buffer and unregister the device
static void __exit dma_exit(void) {
    // Free the DMA buffer
    if (dma_buffer) {
        dma_free_coherent(NULL, DMA_BUFFER_SIZE, dma_buffer, dma_handle);
    }

    // Remove the character device
    cdev_del(&my_cdev);
    unregister_chrdev_region(dev_num, 1);

    printk(KERN_INFO "DMA device driver exited\n");
}

module_init(dma_init);
module_exit(dma_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple DMA Buffer Kernel Module");
MODULE_AUTHOR("Example Author");
