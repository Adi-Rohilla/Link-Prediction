#include <iostream>
#include <cstdlib>
using namespace std;
struct Family_tree
{
struct Family_tree *left, *right;
int key, disease;
};
//creating a new node for a family member
struct Family_tree* newMember(int key, int disease)
{
struct Family_tree* ptr = new Family_tree;
ptr->key = key;
ptr->disease = disease;
ptr->left = ptr->right = NULL;
return ptr;
}
//inserting the family member in the family tree
struct Family_tree* insert(struct Family_tree* root, int key, int disease)
{
if(!root)
root = newMember(key, disease);
else if(root->key > key)
root->left = insert(root->left, key, disease);
else if(root->key < key)
root->right = insert(root->right, key, disease);
return root;
}
//Calculating the distance of a node from the root
int distance(struct Family_tree* root, int x)
{
if(root->key == x)
return 0;
else if(root->key > x)
return (distance(root->left, x) + 1);
else
return (distance(root->right, x) + 1);
}
void implement(int members[31], int keys[31])
{

struct Family_tree* root = NULL;
cout<<"The sequence: "<<endl;
for(int i=0;i<31;i++)
{
cout<<members[i]<<" ";
}
cout<<endl;
for(int i=0;i<31;i++)
{
root = insert(root, keys[i], members[i]);
}
double total_distance=0, total_impact_distance=0;
for(int i=1;i<31;i++)
{
double dist = 1/(double)distance(root,keys[i]);
total_distance += dist;
if(members[i]==1)
{
total_impact_distance += dist;
}
}
double chance = (total_impact_distance/total_distance)*100;
cout<<"The chances of occurance of the disease are: "<<chance<<"%"<<endl;;
}
int main()
{
int keys[31];
keys[0]=16;
keys[1]=8;
keys[2]=24;
keys[3]=4;
keys[4]=12;
keys[5]=20;
keys[6]=28;
keys[7]=2;
keys[8]=6;
keys[9]=10;
keys[10]=14;
keys[11]=18;
keys[12]=22;
keys[13]=26;
keys[14]=30;
keys[15]=1;
keys[16]=3;
keys[17]=5;
keys[18]=7;
keys[19]=9;

keys[20]=11;
keys[21]=13;
keys[22]=15;
keys[23]=17;
keys[24]=19;
keys[25]=21;
keys[26]=23;
keys[27]=25;
keys[28]=27;
keys[29]=29;
keys[30]=31;
int members[10][31];
for(int i=0;i<10;i++)
{
members[i][0]=0;
for(int j=1;j<31;j++)
{
members[i][j] = rand()%2;
}
implement(members[i],keys);
}
int members1[31] = {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
implement(members1,keys);
}