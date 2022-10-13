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
