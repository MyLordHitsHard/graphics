#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iomanip>
typedef struct
{
int p_Id; int ex; int pr; int rt; int ready; int dl; int flag;
}
Process;
using namespace std;
bool cmp(Process a, Process b)
{
return (a.pr < b.pr);
}

int take_lcm(vector<Process> data, int limit)
{
int maax1, maax2, counter = 1;
bool notfound = true;
maax2 = maax1 = data[limit - 1].pr;
while (notfound) {
for (int j = 0; j < limit - 1; j++)
{
if (!(maax2 % data[j].pr));
else break;
if (j == (limit - 2)) {
notfound = false;
break;
}
}
if (notfound) break;
else {
maax2 = maax1 * (++counter);
}
}
return maax2;
}






int main() {
int no, ex, pr, lcm, counter = 0;
double utilization = 0;
int totalExecutionTime = 0;
vector<Process> data;
Process temp;
cout << "Enter number of processes: " << endl;
cin >> no;
cout << "Enter data for each process: " << endl;
for (int i = 1; i <= no; i++) {
cout << "P" << i << " \n"
<< "Execution time : ";
cin >> ex;
cout << "Period : ";
cin >> pr;
cout << endl;
temp.p_Id = i;
