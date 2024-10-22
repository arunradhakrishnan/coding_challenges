import torchvision
import matplotlib as mp

print ("hello world")

import torch

# Create a tensor
x = torch.tensor([1, 2, 3, 4])
print(x)

# Operations on tensors
y = torch.ones(4)
print(x + y)


x = torch.tensor([1.0, 2.0, 3.0, 4.0], requires_grad=True)
y = x * 2
z = y.mean()
z.backward()  # Compute gradients
print(x.grad)


import torch.nn as nn

class SimpleNN(nn.Module):
    def __init__(self):
        super(SimpleNN, self).__init__()
        self.linear = nn.Linear(4, 1)

    def forward(self, x):
        return self.linear(x)

model = SimpleNN()
print(model)

# Dummy data
inputs = torch.randn(10, 4)
targets = torch.randn(10, 1)

# Model, loss function, and optimizer
model = SimpleNN()
criterion = nn.MSELoss()
optimizer = torch.optim.SGD(model.parameters(), lr=0.01)

# Training loop
for epoch in range(100):
    # Forward pass
    outputs = model(inputs)
    loss = criterion(outputs, targets)

    # Backward pass and optimization
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    if (epoch + 1) % 10 == 0:
        print(f'Epoch [{epoch+1}/100], Loss: {loss.item():.4f}')

from torch.utils.data import DataLoader, TensorDataset

dataset = TensorDataset(inputs, targets)
dataloader = DataLoader(dataset, batch_size=2, shuffle=True)

for batch in dataloader:
    print(batch)
