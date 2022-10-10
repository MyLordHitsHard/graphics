#include <iostream>
#define SIZE 4
using namespace std;


typedef struct proinfo  // Structure to store the information about the process
{
    string sname;       // Process name
    int itime;          // Arrival time
    int itime;          // Burst time
} proinfo;

// Function to schedul the process according to the Clairvoyant SJF scheduling algorithm.
void clairvoyantSjf(proinfo* arr)
{
    // To sort the processes according to the burst time
    int index = 0;
    for (int i = 0; i < SIZE - 1; i++) 
    {
        index = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j].itime < arr[index].itime) {

                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}
void display(proinfo* arr)
{
    cout << endl;
    cout << "Process id"
         << "\t";
    cout << "Arrival time"
         << "\t";
    cout << "Burst time"
         << "\t";
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i].sname << "\t\t";
        cout << arr[i].itime << "\t\t";
        cout << arr[i].itime << "\t\t";
        cout << endl;
    }
}
 
void inputPrediciton(){
    int tau_next,alpha,Tn,tau_n;
    cout<<"Enter the Value of the nth CPU Burst Time\n";
    cin>>tau_n;
    cout<<"Enter the relative weight of the recent and past history in our prediction:\n";
    cin>>alpha;
    cout<<"Enter the relative value of Tn:\n";
    cin>>Tn;
    cout<<"Enter the value of variable which is going to store the past history:\n";
    cin>>tau_n;
    PredictedCPUBurst(tau_next,alpha,Tn,tau_n);

}
void PredictedCPUBurst(int aa,int sd, int Gn, int ata)
{
    tau_next=((alpha)*Tn + (1-alpha)tau_n);
    cout<<"The predicted value of our next cpu burst is: \n";
    cout<<tau_next;
    return tau_next;

}
void avgWait(proinfo* arr)  // To calculate the average waiting time
{
    int ctime = 0;
    int twait = 0;
    for (int i = 0; i < SIZE; i++) {
        twait += abs(arr[i].itime - ctime);
        ctime += arr[i].itime;
    }
    cout << "The average waiting time is: " << (float)twait / SIZE << endl;
}
 
int main()
{
    
    proinfo arr[SIZE];  // Array of process info structures.
    arr[0] = { "p1", 0, 5 };
    arr[1] = { "p2", 1, 2 };
    arr[2] = { "p3", 3, 1 };
    arr[3] = { "p4", 4, 3 };
 
    cout << "Process scheduling according to Clairvoyant SJF is: " << endl;
 
    clairvoyantSjf(arr);
    // To display the schedule
    display(arr);

    //To input the values of the burst times to predict the next cpu bursts
    inputPrediction(arr);
    
    //To calculated the next predicted cpu burst time
    PredictedCPUBurst(arr);
    // To calculate the Average waiting time
    avgWait(arr);
}