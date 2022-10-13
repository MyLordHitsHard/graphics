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

temp.ex = ex;
temp.pr = pr;
temp.ready = 1;
temp.rt = ex;
temp.dl = pr;
temp.flag = 0;
data.push_back(temp);
}
sort(data.begin(), data.end(), cmp);
lcm = take_lcm(data, no);
cout << "Process No.\t\tExecution time \t\t Period" << endl;
for (int i = 0; i < no; i++) {
totalExecutionTime += (lcm / data[i].pr) * data[i].ex;
cout << " " << data[i].p_Id << "\t\t\t\t" << data[i].ex << "\t\t " 
<< data[i].pr << endl;
}
if (totalExecutionTime > lcm) {
cout << "\n\nTotal execution time is more than LCM so RMS 
is not feasible in this" << 
endl;
return 0;
}
utilization = (totalExecutionTime * 1.0 / lcm) * 100;
cout << setprecision(4) << "\n\nUtilization = " << utilization 
<< "%\n";
cout << "\n\nLCM = " << lcm << endl;
cout << "\n Time" << "\t\t Running Process" << "\t\t 
deadline\n";
for (int i = 0; i < lcm; i++) {
bool first = true;
int miin = 1000000;
if ((i + 1) >= data[0].pr)
{
for (int j = 0; j < no; j++) {
if (!(i % data[j].pr)) {
data[j].ready = 1;
data[j].dl = data[j].pr;
}
if (data[j].dl <= miin && data[j].ready) {
if (data[j].dl == miin && data[j].flag) counter++;
else miin = data[j].dl;
}
--data[j].dl; //reducing deadline by 1
if (!((i + 1) % data[j].pr))
{
if (first) {
cout << "\t\t\t\t\t\tP" << j + 1;
first = false;
}
else cout << " , P" << j + 1;
}
}
cout << "\r";
}
else
for (int j = 0; j < no; j++) {
if (data[j].dl <= miin && data[j].ready) {
if (data[j].dl == miin && data[j].flag) counter++;
else miin = data[j].dl;
}
--data[j].dl; //reducing deadline by 1
}
cout << " " << i;
for (int j = 0; j < no; j++) {
if (counter) {
if (data[j].ready && data[j].dl + 1 == miin && data[j].flag)
{
data[j].flag = 0;
counter = 0;
if (data[j].rt) { // Remaining execution time
if (!(--(data[j].rt))) { //Reduce Remaining execution time and 
checking it
data[j].ready = 0;
data[j].rt = data[j].ex;
}
else data[j].flag = 1;
}
cout << "\t\t\tP" << data[j].p_Id; break;
}
} else {
if (data[j].ready && data[j].dl + 1 == miin) {
if (data[j].rt)
{
if (!(--(data[j].rt)))
{
data[j].ready = 0;
data[j].rt = data[j].ex;
}
else
data[j].flag = 1;
}
cout << "\t\t\tP" << data[j].p_Id;
break;
}
}
}
cout << endl;
}
return 0;
}
