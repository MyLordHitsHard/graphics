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
