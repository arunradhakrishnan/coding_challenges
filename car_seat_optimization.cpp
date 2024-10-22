#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort and std::min
#include <unistd.h>
using namespace std;

int optimizeCarUsage(vector<int>& currentCarPassengers, vector<int>& currentSeatsVacant) {

int i = 0;
int j = 0;
int number_cars = currentCarPassengers.size();
int done = 0;




for(int i = 0; i< currentCarPassengers.size(); i++ )
{
    for(int j = 0; j< currentSeatsVacant.size(); j++ )
    {
     //sleep(1);
            cout <<"i " <<  i << " j " << j << "\n";
        // cout << "currentSeatsVacant[j]" << currentSeatsVacant[j] << " ";
        // cout << "currentCarPassengers[i]" << currentCarPassengers[i] << "\n";
    if(i != j)
        {


        if(currentSeatsVacant[j] == 0)
                continue;
        if(currentCarPassengers[i] == 0)
                continue;

        if(currentCarPassengers[i] == currentSeatsVacant[j])
            {
                number_cars--;
                currentCarPassengers[j] = currentCarPassengers[j] + currentCarPassengers[i];
                currentCarPassengers[i] = 0;
                currentSeatsVacant[j] = 0;
                
            }
        
        }
     }
    cout << "=====================================\n";
}

        for(int k = 0; k< currentCarPassengers.size(); k++ )
        cout << "after currentSeatsVacant[j]" << currentSeatsVacant[k] << "\n";
        for(int l = 0; l< currentCarPassengers.size(); l++ )
        cout << "after currentCarPassengers[i]" << currentCarPassengers[l] << "\n";

return number_cars;


}






 main() {
    // Example input: Seat capacity and current occupancy of each car.

    vector<int> currentCarPassengers = {1, 5, 1, 1, 1};   // Passengers in car.
    vector<int> currentSeatsVacant = {1, 4, 1, 1, 2};  // Current vacant in each car.

    // Step 2: Optimize car usage.
    int res = optimizeCarUsage(currentCarPassengers, currentSeatsVacant);
    cout << " res " << res << "\n";
    return 0;
}
