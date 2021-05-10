#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
           COLOR CODES
 -----------------------------------
 Color  |  Clockwise  | Anticlockwise
 ------ |-------------|-------------
 white  |     0       |     6
 red    |     1       |     7
 green  |     2       |     8
 blue   |     3       |     9
 orange |     4       |     10
 yellow |     5       |     11
 */

struct blockMatrix
{
    vector<int> color = {-1, -1, -1};
    vector<vector<int>> v21 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
};

struct faceMatrix
{
    vector<int> v1 = {0, 0, 0};
    vector<int> v2 = {0, 0, 0};
};

struct faceMatrix matrixes[6][9];
struct faceMatrix matrixes1[6][9];

struct blockMatrix block[3][3][3];

vector<vector<int>> arr = {{0, 1, 3, 2, 4,5}, {1, 5, 3, 2, 0,4}, {2, 5, 1, 4, 0,3}, {3, 5, 4, 1, 0,2}, {4, 5, 2, 3, 0,1}, {5, 4, 3, 2, 1,0}};
vector<vector<int>> arr1 = {{0,0,-1},{1 ,0,0},{0,1,0},{0,-1,0},{-1,0,0},{0,0,1}};

vector<vector<int>> white(3, vector<int>(3));
vector<vector<int>> red(3, vector<int>(3));
vector<vector<int>> green(3, vector<int>(3));
vector<vector<int>> blue(3, vector<int>(3));
vector<vector<int>> orange(3, vector<int>(3));
vector<vector<int>> yellow(3, vector<int>(3));

int totalSteps=0;

//TO CHECK FOR PERMUTATIONS
int permutations(vector<int> m1)
{
    sort(m1.begin(), m1.end());
    int m = m1[2] * 100 + m1[1] * 10 + m1[0];
    return m;
}

//TO SEARCH FOR THE GIVEN VECTOR
vector<int> find(vector<int> colors)
{
    int x = permutations(colors);
    vector<int> v1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int y = permutations(block[i][j][k].color);
                if (x == y)
                {
                    v1 = {i, j, k};
                    break;
                }
            }
        }
    }
    return v1;
}

//TO COPY MATRIXES IN MATRIXES1
void copy1(){
    for(int i=0 ; i<6 ; i++){
        for(int j=0 ; j<9 ; j++){
            matrixes1[i][j]=matrixes[i][j];
        }
    }

}

//TO COPY MATRIXES1 IN MATRIXES
void copy2(){
    for(int i=0 ; i<6 ; i++){
        for(int j=0 ; j<9 ; j++){
            matrixes[i][j]=matrixes1[i][j];
        }
    }

}

//TO CALCULATE SUM OF THE GIVEN VECTORS
vector <int> sum(vector<int> a , vector<int> b , vector<int> c){
    vector<int> d={0,0,0};
    for(int i=0 ; i<3 ; i++){
        d[i]=a[i]+b[i]+c[i];
    }
   return d; 
}

//ADDING ELEMENTS TO BLOCK MATRIX
void addToBlockMatrix(int center, vector<int> colorArray)
{
    vector<vector<int>> red = {{1, -1, 1}, {1, 0, 1}, {1, 1, 1}, {1, -1, 0}, {1, 0, 0}, {1, 1, 0}, {1, -1, -1}, {1, 0, -1}, {1, 1, -1}};
    vector<vector<int>> green = {{1, 1, 1}, {0, 1, 1}, {-1, 1, 1}, {1, 1, 0}, {0, 1, 0}, {-1, 1, 0}, {1, 1, -1}, {0, 1, -1}, {-1, 1, -1}};
    vector<vector<int>> orange = {{-1, 1, 1}, {-1, 0, 1}, {-1, -1, 1}, {-1, 1, 0}, {-1, 0, 0}, {-1, -1, 0}, {-1, 1, -1}, {-1, 0, -1}, {-1, -1, -1}};
    vector<vector<int>> blue = {{-1, -1, 1}, {0, -1, 1}, {1, -1, 1}, {-1, -1, 0}, {0, -1, 0}, {1, -1, 0}, {-1, -1, -1}, {0, -1, -1}, {1, -1, -1}};
    vector<vector<int>> white = {{1, -1, -1}, {1, 0, -1}, {1, 1, -1}, {0, -1, -1}, {0, 0, -1}, {0, 1, -1}, {-1, -1, -1}, {-1, 0, -1}, {-1, 1, -1}};
    vector<vector<int>> yellow = {{-1, -1, 1}, {-1, 0, 1}, {-1, 1, 1}, {0, -1, 1}, {0, 0, 1}, {0, 1, 1}, {1, -1, 1}, {1, 0, 1}, {1, 1, 1}};

    for (int i = 0; i < 9; i++)
    {
        if (center == 0)
        {
            white[i][0]++;
            white[i][1]++;
            white[i][2]++;
            block[white[i][0]][white[i][1]][white[i][2]].color[2] = colorArray[i];
            block[white[i][0]][white[i][1]][white[i][2]].v21[2] = {0, 0, -1};
        }
        else if (center == 1)
        {
            red[i][0]++;
            red[i][1]++;
            red[i][2]++;
            block[red[i][0]][red[i][1]][red[i][2]].color[0] = colorArray[i];
            block[red[i][0]][red[i][1]][red[i][2]].v21[0] = {1, 0, 0};
        }
        else if (center == 2)
        {
            green[i][0]++;
            green[i][1]++;
            green[i][2]++;
            block[green[i][0]][green[i][1]][green[i][2]].color[1] = colorArray[i];
            block[green[i][0]][green[i][1]][green[i][2]].v21[1] = {0, 1, 0};
        }
        else if (center == 3)
        {
            blue[i][0]++;
            blue[i][1]++;
            blue[i][2]++;
            block[blue[i][0]][blue[i][1]][blue[i][2]].color[1] = colorArray[i];
            block[blue[i][0]][blue[i][1]][blue[i][2]].v21[1] = {0, -1, 0};
        }
        else if (center == 4)
        {
            orange[i][0]++;
            orange[i][1]++;
            orange[i][2]++;
            block[orange[i][0]][orange[i][1]][orange[i][2]].color[0] = colorArray[i];
            block[orange[i][0]][orange[i][1]][orange[i][2]].v21[0] = {-1, 0, 0};
        }
        else
        {
            yellow[i][0]++;
            yellow[i][1]++;
            yellow[i][2]++;
            block[yellow[i][0]][yellow[i][1]][yellow[i][2]].color[2] = colorArray[i];
            block[yellow[i][0]][yellow[i][1]][yellow[i][2]].v21[2] = {0, 0, 1};
        }
    }
}

vector<int> colors;

//FOR CREATING FACE MATRIX
void createFaceMatrix()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (j == 8)
            {
                colors.push_back(i);
                colors.push_back(arr[i][2]);
                colors.push_back(arr[i][1]);
            }
            if (j == 1)
            {
                colors.push_back(i);
                colors.push_back(arr[i][1]);
                colors.push_back(-1);
            }
            if (j == 5)
            {
                colors.push_back(i);
                colors.push_back(arr[i][3]);
                colors.push_back(arr[i][1]);
            }
            if (j == 4)
            {
                colors.push_back(i);
                colors.push_back(arr[i][2]);
                colors.push_back(-1);
            }
            if (j == 0)
            {
                colors.push_back(i);
                colors.push_back(-1);
                colors.push_back(-1);
            }
            if (j == 2)
            {
                colors.push_back(i);
                colors.push_back(arr[i][3]);
                colors.push_back(-1);
            }
            if (j == 7)
            {
                colors.push_back(i);
                colors.push_back(arr[i][2]);
                colors.push_back(arr[i][4]);
            }
            if (j == 3)
            {
                colors.push_back(i);
                colors.push_back(arr[i][4]);
                colors.push_back(-1);
            }
            if (j == 6)
            {
                colors.push_back(i);
                colors.push_back(arr[i][3]);
                colors.push_back(arr[i][4]);
            }
            vector<int> v = find(colors);
            int x;
            for (int l = 0; l < 3; l++)
            {
                if (block[v[0]][v[1]][v[2]].color[l] == i)
                {
                    matrixes[i][j].v2 = block[v[0]][v[1]][v[2]].v21[l];
                    break;
                }
            }
            v[0]--;
            v[1]--;
            v[2]--;
            colors.clear();
            matrixes[i][j].v1 = v;
        }
    }
}

//UTILITY FUNCTION FOR PRINTING 1D VECTOR ELEMENTS
void printArr1D(vector<int> a)
{
    for (int j = 0; j < 3; j++)
    {
        cout << a[j] << " ";
    }
}

//UTILITY FUNCTION FOR PRINTING 2D VECTOR ELEMENTS
void printArr2D(vector<vector<int>> a)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

//TO PRINT BLOCK MATRIX
void printBlockMatrix()
{
    cout << "---------------------\n";
    cout << "PRINTING BLOCK MATRIX\n";
    cout << "---------------------\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "[\n\n";
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printArr1D(block[i][j][k].color);
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "]\n\n";
    }
}

//TO PRINT FACE MATRIX
void printFaceMatrix()
{
    cout << "--------------------------\n";
    cout << "PRINTING FACE MATRIX\n";
    cout << "--------------------------\n";
    for (int i = 0; i < 6; i++)
    {
        cout << "Face " << i << "\n";
        for (int j = 0; j < 9; j++)
        {
            cout << "v1: ";
            printArr1D(matrixes[i][j].v1);
            cout << "   v2: ";
            printArr1D(matrixes[i][j].v2);
            cout << "\n";
        }
        cout << "--------------------\n";
    }
}

//CREATING BLOCK MATRIX
void createBlockMatrix()
{
    for (int i = 0; i < 6; i++)
    {
        vector<int> a(9);
        for (int j = 0; j < 9; j++)
        {
            cin >> a[j];
        }
        addToBlockMatrix(a[4], a);
    }
}

//TO GENERATE THE CURRENT STATE OF CUBE
void createFaces(){
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            vector<int> currV1 = matrixes[i][j].v1;
            vector<int> currV2 = matrixes[i][j].v2;

            if (currV2[0] == 1)
            {
                red[-currV1[2] + 1][currV1[1] + 1] = i;
            }
            else if (currV2[0] == -1)
            {
                orange[-currV1[2] + 1][-currV1[1] + 1] = i;
            }
            else if (currV2[1] == 1)
            {
                green[-currV1[2] + 1][-currV1[0] + 1] = i;
            }
            else if (currV2[1] == -1)
            {
                blue[-currV1[2] + 1][currV1[0] + 1] = i;
            }
            else if (currV2[2] == 1)
            {
                yellow[currV1[0] + 1][currV1[1] + 1] = i;
            }
            else if (currV2[2] == -1)
            {
                white[-currV1[0] + 1][currV1[1] + 1] = i;
            }
        }
    }
}

//TO PRINT ALL FACES
void printAllFaces()
{   
    createFaces();
    cout << "-------------------\n";
    cout << "PRINTING ALL FACES\n";
    cout << "-------------------\n";
    printArr2D(white);
    printArr2D(red);
    printArr2D(green);
    printArr2D(blue);
    printArr2D(orange);
    printArr2D(yellow);
}

//TO CALCULATE CROSS PRODUCT
void cross_product(vector<int> v1, vector<int> v2, vector<int> &cproduct)
{
    cproduct[0] = v1[1] * v2[2] - v1[2] * v2[1];
    cproduct[1] = v1[2] * v2[0] - v1[0] * v2[2];
    cproduct[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

//TO ROTATE THE GIVEN FACE(works for both clockwise and anticlockwise rotation)
void rotate(int x)
{
    vector<vector<int>> codes = {{0, 0, -1}, {1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}};
    
    if (x<=5){

        vector<int> v3 = codes[x];

        int index;
        if (v3[0]) index=0;
        else if (v3[1]) index=1;
        else index=2;

        for(int i=0;i<6;i++){
            for(int j=0;j<9;j++){

                if (matrixes[i][j].v1[index]==v3[index]){
                    
                    vector <int> cproduct13(3), cproduct23(3);

                    cross_product(matrixes[i][j].v1, v3, cproduct13);
                    for (int k = 0; k < 3; k++)  matrixes[i][j].v1[k] = cproduct13[k] + v3[k];
        
                    if (matrixes[i][j].v2[index]!=v3[index]){
                        cross_product(matrixes[i][j].v2,v3,cproduct23);
                        for (int k=0;k<3;k++) matrixes[i][j].v2[k] = cproduct23[k];
                    }
                }
            }
        }
        
    }
    else if(x>5 && x<12){
        vector <int> v3_= codes[x];
        vector <int> v3 = codes[(x + 6) % 12];

        int index;
        if (v3[0]) index=0;
        else if (v3[1]) index=1;
        else index=2;

        for(int i=0;i<6;i++){
            for(int j=0;j<9;j++){

                if (matrixes[i][j].v1[index]==v3[index]){

                    vector <int> cproduct13(3), cproduct23(3);

                    cross_product(matrixes[i][j].v1, v3_, cproduct13);
                    for (int k = 0; k < 3; k++)  matrixes[i][j].v1[k] = cproduct13[k] + v3[k];

                    if ( matrixes[i][j].v2[index]!=v3[index]){
                        cross_product(matrixes[i][j].v2,v3_,cproduct23);
                        for (int k=0;k<3;k++) matrixes[i][j].v2[k] = cproduct23[k];
                    }
                }
            }
        }
    }
}

//UTILITY FUNCTION FOR MAKING WHITE CROSS
void place(int p,vector <int> &ans,int &t1){

    vector<int> vw1 =matrixes[p][3].v1;
    vector<int> vw2 =matrixes[p][3].v2;
    vector<int> v= {0,0,0};
        if(vw1==sum(arr1[arr[p][0]],arr1[arr[p][3]],v)){
        // cout<<1<<endl;
            if(vw2==arr1[arr[p][0]]){
                rotate(arr[p][0]);

                ans[t1++]=arr[p][0];
            }
            else{
                rotate(arr[p][3]);rotate(5);rotate(arr[p][3]+6);
                rotate(arr[p][0]);rotate(arr[p][0]);

                ans[t1++]=arr[p][3];ans[t1++]=5;ans[t1++]=arr[p][3]+6;
                ans[t1++]=arr[p][0];ans[t1++]=arr[p][0];
            }
        }
        else if(vw1==sum(arr1[arr[p][0]],arr1[arr[p][2]],v)){
        // cout<<2<<endl;
            if(vw2==arr1[arr[p][0]]){
                rotate(arr[p][0]+6);

                ans[t1++]=arr[p][0]+6;
            }
            else{
                rotate(arr[p][2]+6);rotate(11);rotate(arr[p][2]);
                rotate(arr[p][0]);rotate(arr[p][0]);

                ans[t1++]=arr[p][2]+6;ans[t1++]=11;ans[t1++]=arr[p][2];
                ans[t1++]=arr[p][0];ans[t1++]=arr[p][0];
            }
        }
        else if(vw1==sum(arr1[arr[p][0]],arr1[arr[p][1]],v)){
        // cout<<3<<endl;
            if(vw2==arr1[arr[p][0]]){
                rotate(arr[p][0]);rotate(arr[p][0]);

                ans[t1++]=arr[p][0];ans[t1++]=arr[p][0];
            }
            else{
                rotate(11);rotate(arr[p][3]+6);rotate(arr[p][0]);rotate(arr[p][3]);

                ans[t1++]=11;ans[t1++]=arr[p][3]+6;ans[t1++]=arr[p][0];ans[t1++]=arr[p][3];
            }
        }
        else if(vw1==sum(arr1[arr[p][0]],arr1[arr[p][4]],v)){
            //cout<<4<<endl;
                if(vw2==arr1[arr[p][4]]){
                    rotate(arr[p][0]+6);
                    rotate(arr[p][3]);rotate(5); rotate(arr[p][3]+6);
                    rotate(arr[p][0]);rotate(arr[p][0]);

                    ans[t1++]=arr[p][0]+6;
                    ans[t1++]=arr[p][3];ans[t1++]=5; ans[t1++]=arr[p][3]+6;
                    ans[t1++]=arr[p][0];ans[t1++]=arr[p][0];
                }
        }
        else if(vw1==sum(arr1[arr[p][4]],arr1[arr[p][3]],v)){
        // cout<<5<<endl;
            if(vw2==arr1[arr[p][4]]){
                rotate(arr[p][3]);
                rotate(arr[p][0]);

                ans[t1++]=arr[p][3];
                ans[t1++]=arr[p][0];
            }
            else{
                rotate(6);rotate(arr[p][0]);
                rotate(0);rotate(arr[p][0]+6);

                ans[t1++]=6;ans[t1++]=arr[p][0];
                ans[t1++]=0;ans[t1++]=arr[p][0]+6;
            }  
        }
    else if(vw1==sum(arr1[arr[p][4]],arr1[arr[p][2]],v)){
        //cout<<6<<endl;
            if(vw2==arr1[arr[p][4]]){
                rotate(arr[p][2]+6);
                rotate(arr[p][0]+6);

                ans[t1++]=arr[p][2]+6;
                ans[t1++]=arr[p][0]+6;
            }
            else{
                rotate(0);rotate(arr[p][0]);
                rotate(6);rotate(arr[p][0]+6);

                ans[t1++]=0;ans[t1++]=arr[p][0];
                ans[t1++]=6;ans[t1++]=arr[p][0]+6;
            }    
        }
    else if(vw1==sum(arr1[arr[p][1]],arr1[arr[p][3]],v)){
        //cout<<7<<endl;
            if(vw2==arr1[arr[p][1]]){
                rotate(arr[p][3]+6);
                rotate(arr[p][0]); rotate(arr[p][3]);

                ans[t1++]=arr[p][3]+6;
                ans[t1++]=arr[p][0]; ans[t1++]=arr[p][3];
            }
            else{
                rotate(5);rotate(arr[p][0]);
                rotate(arr[p][0]);

                ans[t1++]=5;ans[t1++]=arr[p][0];
                ans[t1++]=arr[p][0];
            }        
        }
    else if(vw1==sum(arr1[arr[p][1]],arr1[arr[p][2]],v)){
        //cout<<8<<endl;
            if(vw2==arr1[arr[p][1]]){
                rotate(arr[p][2]);
                rotate(arr[p][0]+6); rotate(arr[p][2]+6);

                ans[t1++]=arr[p][2];
                ans[t1++]=arr[p][0]+6; ans[t1++]=arr[p][2]+6;
            }
            else{
                rotate(11);rotate(arr[p][0]);
                rotate(arr[p][0]);

                ans[t1++]=11;ans[t1++]=arr[p][0];
                ans[t1++]=arr[p][0];
            }          
        }
        else if(vw1==sum(arr1[arr[p][4]],arr1[arr[p][5]],v)){
        // cout<<9<<endl;
            if(vw2==arr1[arr[p][5]]){
                rotate(0); rotate(0); rotate(arr[p][0]);
                rotate(6); rotate(6); rotate(arr[p][0]+6);

                ans[t1++]=0; ans[t1++]=0; ans[t1++]=arr[p][0];
                ans[t1++]=6; ans[t1++]=6; ans[t1++]=arr[p][0]+6;
            }
            else{
                rotate(0);rotate(arr[p][2]+6);rotate(6);
                rotate(arr[p][0]+6);

                ans[t1++]=0;ans[t1++]=arr[p][2]+6;ans[t1++]=6;
                ans[t1++]=arr[p][0]+6;
            }     
        }
        else if(vw1==sum(arr1[arr[p][3]],arr1[arr[p][5]],v)){
        // cout<<10<<endl;
            if(vw2==arr1[arr[p][5]]){
                rotate(arr[p][3]); rotate(arr[p][3]);
                rotate(arr[p][0]);rotate(arr[p][3]+6); rotate(arr[p][3]+6);

                ans[t1++]=arr[p][3]; ans[t1++]=arr[p][3];
                ans[t1++]=arr[p][0];ans[t1++]=arr[p][3]+6; ans[t1++]=arr[p][3]+6;
            }
            else{
                rotate(arr[p][3]);rotate(6);rotate(arr[p][0]+6);
                rotate(0);rotate(arr[p][0]);rotate(arr[p][3]+6);

                ans[t1++]=arr[p][3];ans[t1++]=6;ans[t1++]=arr[p][0]+6;
                ans[t1++]=0;ans[t1++]=arr[p][0];ans[t1++]=arr[p][3]+6;
            }     
        }
        else if(vw1==sum(arr1[arr[p][2]],arr1[arr[p][5]],v)){
        // cout<<11<<endl;
            if(vw2==arr1[arr[p][5]]){
                rotate(arr[p][2]+6); rotate(arr[p][2]+6);
                rotate(arr[p][0]+6);rotate(arr[p][2]); rotate(arr[p][2]);

                ans[t1++]=arr[p][2]+6;ans[t1++]=arr[p][2]+6;
                ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][2];ans[t1++]=arr[p][2];
            }
            else{
                rotate(arr[p][2]+6);rotate(0);rotate(arr[p][0]);
                rotate(6);rotate(arr[p][0]+6);rotate(arr[p][2]);
                
                ans[t1++]=arr[p][2]+6;ans[t1++]=0;ans[t1++]=arr[p][0];
                ans[t1++]=6;ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][2];
            }     
        }
        else if(vw1==sum(arr1[arr[p][1]],arr1[arr[p][5]],v)){
        // cout<<12<<endl;
            if(vw2==arr1[arr[p][5]]){
                rotate(5); rotate(5);
                rotate(arr[p][0]);rotate(arr[p][0]); 

                ans[t1++]=5;ans[t1++]=5;
                ans[t1++]=arr[p][0];ans[t1++]=arr[p][0];
            }
            else{
                rotate(5); rotate(arr[p][3]+6);
                rotate(arr[p][0]);rotate(arr[p][3]);

                ans[t1++]=5;ans[t1++]=arr[p][3]+6;
                ans[t1++]=arr[p][0];ans[t1++]=arr[p][3];
            }     
        }
        
}



// TO MAKE WHITE CROSS
void makeWhiteCross(){
    vector<int> answer(30);
    vector<int> tmp_ans(30);
    int anslen=30 , templen=0;
    for(int i=1; i<5 ; i++){
        for(int j=1 ; j<5 ; j++){
            for(int k=1 ; k<5 ; k++){
                for(int l=1 ; l<5 ;l++){
                    
                    if(!(i==j || i==k || i==l || j==k || j==l || k==l)){

                        templen=0;
                        copy1();
                        
                        place(i,tmp_ans , templen); 
                        place(j,tmp_ans , templen); 
                        place(k,tmp_ans , templen); 
                        place(l,tmp_ans , templen); 

                        
                        if(anslen>templen){
                            anslen=templen;
                            for(int c=0 ; c<templen ; c++){
                                answer[c]=tmp_ans[c];
                            }
                        }

                        copy2();
                    }

                }
            }
        }
    }
     
    totalSteps+=anslen;
    cout<<"Total Steps for WHITE CROSS: "<<anslen<<"\n";
    for(int m=0 ; m<anslen ; m++){
        cout<<answer[m]<<" ";
        rotate(answer[m]);
    }
    cout<<endl;
}



//UTILITY FUNCTION FOR IMPLEMENTING F2L ALGORITHM
void dostep2(int p,vector<int> &vc1 , vector<int> &vc2 , vector<int> &ve1 ,vector<int> &ve2 ,vector<int> &v,vector<int> &vw2,vector<int> &ans , int &t1){
if(vc1[2]==1 && ve1[2]==1){
    //cout<<1<<endl;
        if(vc2==arr1[arr[p][1]] && vw2==arr1[arr[p][0]] ){
            if(ve2==arr1[arr[p][1]]){
                if(ve1== sum(arr1[arr[p][3]],arr1[arr[p][1]],v)){
                    //correct
                    //cout<<"c"<<endl;
                    rotate(arr[p][1]);rotate(arr[p][3]);rotate(arr[p][1]+6);rotate(arr[p][3]+6);

                    ans[t1++]=arr[p][1];ans[t1++]=arr[p][3];ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3]+6;
                }
                else if(ve1== sum(arr1[arr[p][0]],arr1[arr[p][1]],v)){
                    //4th 2ndcase
                    //cout<<"d"<<endl;
                    rotate(arr[p][0]+6);rotate(arr[p][1]);rotate(arr[p][0]);rotate(arr[p][1]+6);
                    rotate(arr[p][1]+6);rotate(arr[p][3]);rotate(arr[p][1]);rotate(arr[p][3]+6);

                    ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1];ans[t1++]=arr[p][0];ans[t1++]=arr[p][1]+6;
                    ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3]+6;
                }
                else if(ve1==sum(arr1[arr[p][2]],arr1[arr[p][1]],v)){
                    //correcth
                    //cout<<"e"<<endl;
                    rotate(arr[p][1]+6);rotate(arr[p][3]);
                    rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][3]+6);
                    rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][3]);rotate(arr[p][1]+6);rotate(arr[p][3]+6);

                    ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3];
                    ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3]+6;
                    ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3];ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3]+6;
                }
                else if(ve1== sum(arr1[arr[p][5]],arr1[arr[p][1]],v)){
                    //correctd
                    //cout<<"f"<<endl;
                    rotate(arr[p][1]+6);rotate(arr[p][3]);
                    rotate(arr[p][1]);rotate(arr[p][3]+6);
                    rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][3]);rotate(arr[p][1]+6);
                    rotate(arr[p][3]+6);

                    ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3];
                    ans[t1++]=arr[p][1];ans[t1++]=arr[p][3]+6;
                    ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3];ans[t1++]=arr[p][1]+6;
                    ans[t1++]=arr[p][3]+6;
                }
               
            }
            else if(ve2==arr1[arr[p][2]]){
                //correct
                //cout<<"g"<<endl;
                rotate(arr[p][0]+6);rotate(arr[p][1]+6);rotate(arr[p][0]);

                ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0];
            }
            else if(ve2==arr1[arr[p][0]]){
                //correcte
                //cout<<"h"<<endl;
                rotate(arr[p][1]);rotate(arr[p][0]+6);rotate(arr[p][1]);rotate(arr[p][0]);rotate(arr[p][1]+6);
                rotate(arr[p][0]+6);rotate(arr[p][1]+6);rotate(arr[p][0]);

                ans[t1++]=arr[p][1];ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1];ans[t1++]=arr[p][0];ans[t1++]=arr[p][1]+6;
                ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0];
            }
            else if(ve2==arr1[arr[p][5]]){
                //correctb
                //cout<<"i"<<endl;
                rotate(arr[p][1]);rotate(arr[p][0]+6);rotate(arr[p][1]+6);rotate(arr[p][0]);rotate(arr[p][1]+6);
                rotate(arr[p][0]+6);rotate(arr[p][1]+6);rotate(arr[p][0]);

                ans[t1++]=arr[p][1];ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0];ans[t1++]=arr[p][1]+6;
                ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0];
            }
            else if(ve2==arr1[arr[p][3]]){
                //correcf
                //cout<<"j"<<endl;
                rotate(arr[p][1]+6);rotate(arr[p][3]);rotate(arr[p][1]);rotate(arr[p][1]);
                rotate(arr[p][3]+6); rotate(arr[p][1]);
                rotate(arr[p][0]+6);rotate(arr[p][1]+6);rotate(arr[p][0]);

                ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3];ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];
                ans[t1++]=arr[p][3]+6; ans[t1++]=arr[p][1];
                ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0];
            }
            
        }
    else if(vc2==arr1[arr[p][0]] && vw2==arr1[arr[p][3]] ){
            if(ve2==arr1[arr[p][1]]){
                
              if(ve1== sum(arr1[arr[p][3]],arr1[arr[p][1]],v)){
                  //correctg
                    //cout<<"k"<<endl;
                    rotate(arr[p][1]+6);rotate(arr[p][3]);rotate(arr[p][1]+6);rotate(arr[p][3]+6);rotate(arr[p][1]);
                    rotate(arr[p][3]); rotate(arr[p][1]); rotate(arr[p][3]+6);

                    ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3];ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3]+6;ans[t1++]=arr[p][1];
                    ans[t1++]=arr[p][3]; ans[t1++]=arr[p][1]; ans[t1++]=arr[p][3]+6;
                }
                else if(ve1== sum(arr1[arr[p][0]],arr1[arr[p][1]],v)){
                   //correctj
                    //cout<<"l"<<endl;
                    rotate(arr[p][3]+6);rotate(arr[p][1]+6);rotate(arr[p][1]+6);rotate(arr[p][3]);
                    rotate(arr[p][3]);rotate(arr[p][1]);rotate(arr[p][3]+6);
                    rotate(arr[p][3]+6);rotate(arr[p][1]);rotate(arr[p][3]);

                    ans[t1++]=arr[p][3]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3];
                    ans[t1++]=arr[p][3];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3]+6;
                    ans[t1++]=arr[p][3]+6;ans[t1++]=arr[p][1];ans[t1++]=arr[p][3];
                }
                else if(ve1==sum(arr1[arr[p][2]],arr1[arr[p][1]],v)){
                    //correctk
                    //cout<<"m"<<endl;
                    rotate(arr[p][1]+6);rotate(arr[p][3]);rotate(arr[p][1]);
                    rotate(arr[p][3]+6);rotate(arr[p][1]);
                    rotate(arr[p][3]);rotate(arr[p][1]);rotate(arr[p][3]+6);

                    ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3];ans[t1++]=arr[p][1];
                    ans[t1++]=arr[p][3]+6;ans[t1++]=arr[p][1];
                    ans[t1++]=arr[p][3];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3]+6;
                }
                else if(ve1==sum(arr1[arr[p][5]],arr1[arr[p][1]],v)){
                    //correct
                    //cout<<"n"<<endl;
                    rotate(arr[p][3]);rotate(arr[p][1]);
                    rotate(arr[p][3]+6);

                    ans[t1++]=arr[p][3];ans[t1++]=arr[p][1];
                    ans[t1++]=arr[p][3]+6;
                }
            }
            else if(ve2==arr1[arr[p][0]]){
                //correct
               // cout<<"o"<<endl;
                rotate(arr[p][1]+6);rotate(arr[p][0]+6);rotate(arr[p][1]);
                rotate(arr[p][0]);

                ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1];
                ans[t1++]=arr[p][0];
            }  
             else if(ve2==arr1[arr[p][3]]){
                 //4th first
                //cout<<"p"<<endl;
                rotate(arr[p][3]);rotate(arr[p][1]+6);rotate(arr[p][3]+6);rotate(arr[p][1]);
                rotate(arr[p][1]);rotate(arr[p][0]+6);rotate(arr[p][1]+6);rotate(arr[p][0]);

                ans[t1++]=arr[p][3];ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3]+6;ans[t1++]=arr[p][1];
                ans[t1++]=arr[p][1];ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0];
            } 
            else if(ve2==arr1[arr[p][5]]){
                //correcti
                //cout<<"q"<<endl;
                rotate(arr[p][1]);rotate(arr[p][0]+6);rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][0]);
                rotate(arr[p][1]+6);rotate(arr[p][1]+6);rotate(arr[p][0]+6);rotate(arr[p][1]);rotate(arr[p][0]);

                ans[t1++]=arr[p][1];ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];ans[t1++]=arr[p][0];
                ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1];ans[t1++]=arr[p][0];
            } 
            else if(ve2==arr1[arr[p][2]]){
                //correcta
                //cout<<"r"<<endl;
                rotate(arr[p][1]);rotate(arr[p][0]+6);rotate(arr[p][1]+6);rotate(arr[p][0]);
                rotate(arr[p][1]+6);rotate(arr[p][1]+6);rotate(arr[p][0]+6);rotate(arr[p][1]);rotate(arr[p][0]);

                ans[t1++]=arr[p][1];ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0];
                ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1];ans[t1++]=arr[p][0];
            } 
        }
        //whiteee uppeerr
   else if(vc2==arr1[arr[p][3]] && vw2==arr1[arr[p][1]]){
            if(ve2==arr1[arr[p][1]]){
                //cout<<"s"<<endl;
                if(ve1== sum(arr1[arr[p][3]],arr1[arr[p][1]],v)){
                    //corrects
                    //cout<<"s1"<<endl;
                    rotate(arr[p][3]);rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][3]+6);
                    rotate(arr[p][1]+6);rotate(arr[p][3]);
                    rotate(arr[p][1]);rotate(arr[p][3]+6);

                    ans[t1++]=arr[p][3];ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3]+6;
                    ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3];
                    ans[t1++]=arr[p][1];ans[t1++]=arr[p][3]+6;
                }
                else if(ve1== sum(arr1[arr[p][0]],arr1[arr[p][1]],v)){
                    //cout<<"s2"<<endl;
                    rotate(arr[p][3]);rotate(arr[p][1]+6);rotate(arr[p][1]+6);rotate(arr[p][3]+6);rotate(arr[p][1]+6);
                    //correct k part
                    rotate(arr[p][1]+6);rotate(arr[p][3]);rotate(arr[p][1]);
                    rotate(arr[p][3]+6);rotate(arr[p][1]);
                    rotate(arr[p][3]);rotate(arr[p][1]);rotate(arr[p][3]+6);

                    ans[t1++]=arr[p][3];ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3]+6;ans[t1++]=arr[p][1]+6;
                    ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3];ans[t1++]=arr[p][1];
                    ans[t1++]=arr[p][3]+6;ans[t1++]=arr[p][1];
                    ans[t1++]=arr[p][3];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3]+6;
                }
                else if(ve1== sum(arr1[arr[p][2]],arr1[arr[p][1]],v)){
                    //cout<<"s3"<<endl;
                    rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][3]);
                    rotate(arr[p][1]);rotate(arr[p][3]+6);rotate(arr[p][1]);
                    rotate(arr[p][3]);rotate(arr[p][1]+6);rotate(arr[p][3]+6);

                    ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3];
                    ans[t1++]=arr[p][1];ans[t1++]=arr[p][3]+6;ans[t1++]=arr[p][1];
                    ans[t1++]=arr[p][3];ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3]+6;
                
                }
                else if(ve1== sum(arr1[arr[p][5]],arr1[arr[p][1]],v)){
                    //correctc
                    //cout<<"s4"<<endl;
                    rotate(arr[p][1]);rotate(arr[p][3]);rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][3]+6);
                    rotate(arr[p][1]);rotate(arr[p][3]);
                    rotate(arr[p][1]+6);rotate(arr[p][3]+6);
                    
                    ans[t1++]=arr[p][1];ans[t1++]=arr[p][3];ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3]+6;
                    ans[t1++]=arr[p][1];ans[t1++]=arr[p][3];
                    ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3]+6;
                }
            }
            // y=?
            else if(ve2==arr1[arr[p][3]]){
                //cout<<"t"<<endl;
                //5th second
                rotate(arr[p][0]);rotate(arr[p][1]);rotate(arr[p][3]);rotate(arr[p][1]+6);
                rotate(arr[p][3]+6);
                rotate(arr[p][0]+6);rotate(arr[p][3]);rotate(arr[p][1]+6);rotate(arr[p][3]+6);

                ans[t1++]=arr[p][0];ans[t1++]=arr[p][1];ans[t1++]=arr[p][3];ans[t1++]=arr[p][1]+6;
                ans[t1++]=arr[p][3]+6;
                ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][3];ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][3]+6;
                
            }
            else if(ve2==arr1[arr[p][5]]){
                //cout<<"u"<<endl;
                
                rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][0]+6);rotate(arr[p][1]+6);rotate(arr[p][0]);
                rotate(arr[p][1]+6);rotate(arr[p][0]+6);rotate(arr[p][1]);rotate(arr[p][0]);
                // rotate(arr[p][1]+6);rotate(arr[p][1]+6);
                // rotate(arr[p][1]+6);rotate(arr[p][0]+6);rotate(arr[p][1]);rotate(arr[p][0]);

                ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0];
                ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1];ans[t1++]=arr[p][0];
            }
            else if(ve2==arr1[arr[p][2]]){
                //cout<<"v"<<endl;
                rotate(arr[p][1]+6);rotate(arr[p][0]+6);rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][0]);
                rotate(arr[p][1]+6);rotate(arr[p][0]+6);rotate(arr[p][1]);rotate(arr[p][0]);
                
                ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];ans[t1++]=arr[p][0];
                ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1];ans[t1++]=arr[p][0];
            }
            else if(ve2==arr1[arr[p][0]]){
                //cout<<"w"<<endl;
                rotate(arr[p][0]+6);rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][0]);
                rotate(arr[p][1]);rotate(arr[p][0]+6);rotate(arr[p][1]+6);rotate(arr[p][0]);
                
                ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1];ans[t1++]=arr[p][1];ans[t1++]=arr[p][0];
                ans[t1++]=arr[p][1];ans[t1++]=arr[p][0]+6;ans[t1++]=arr[p][1]+6;ans[t1++]=arr[p][0];
            }

        }

    }
    
}

//UTILITY FUNCTION FOR IMPLEMENTING F2L ALGORITHM
void place2(int p,vector<int> &ans , int &t1){
    vector <int> vc1 = matrixes[p][6].v1;
    vector <int> vc2 = matrixes[p][6].v2;
    vector <int> ve1 = matrixes[p][2].v1;
    vector <int> ve2 = matrixes[p][2].v2;
    vector<int> v={0,0,0};
    //cout<<"enter"<<endl;
 
    if(ve1[2]!=1){
        //cout<<8<<endl;
        if(ve1==sum(arr1[arr[p][2]],arr1[arr[p][0]],v)){
            rotate(arr[p][2]+6);
            rotate(5);
            rotate(arr[p][2]);

            ans[t1++]=arr[p][2]+6; ans[t1++]=5; ans[t1++]=arr[p][2];
        }
        else if(ve1==sum(arr1[arr[p][2]],arr1[arr[p][5]],v)){
            rotate(arr[p][2]);
            rotate(5);
            rotate(arr[p][2]+6);

            ans[t1++]=arr[p][2]; ans[t1++]=5; ans[t1++]=arr[p][2]+6;
        }
        else if(ve1==sum(arr1[arr[p][3]],arr1[arr[p][5]],v)){
            rotate(arr[p][5]);
            rotate(5);
            rotate(arr[p][5]+6);

            ans[t1++]=arr[p][5]; ans[t1++]=5; ans[t1++]=arr[p][5]+6;
        }
        else if(ve1==sum(arr1[arr[p][3]],arr1[arr[p][0]],v)){
            rotate(arr[p][3]);
            rotate(5);
            rotate(arr[p][3]+6);

            ans[t1++]=arr[p][3]; ans[t1++]=5; ans[t1++]=arr[p][3]+6;
        }
    }

    vc1 = matrixes[p][6].v1;
    vc2 = matrixes[p][6].v2;
    ve1 = matrixes[p][2].v1;
    ve2 = matrixes[p][2].v2;

    if(ve1[2]!=1) cout<<"wrong"<<endl;

    if(vc1[2]==-1){
        // cout<<9<<endl;
        if(vc1==sum(arr1[arr[p][3]],arr1[arr[p][5]],arr1[arr[p][4]])){
            if(ve1==sum(arr1[arr[p][2]],arr1[arr[p][1]],v)) {
            rotate(arr[p][5]);
            rotate(11);
            rotate(arr[p][5]+6);

            ans[t1++]=arr[p][5]; ans[t1++]=11; ans[t1++]=arr[p][5]+6;
            }
            else{
            rotate(arr[p][5]);
            rotate(5);
            rotate(arr[p][5]+6);

            ans[t1++]=arr[p][5]; ans[t1++]=5; ans[t1++]=arr[p][5]+6;
            }
            
        }
        else if(vc1==sum(arr1[arr[p][2]],arr1[arr[p][5]],arr1[arr[p][4]])){
            if(ve1==sum(arr1[arr[p][2]],arr1[arr[p][1]],v)){
            rotate(arr[p][5]+6);
            rotate(11);
            rotate(arr[p][5]);

            ans[t1++]=arr[p][5]+6; ans[t1++]=11; ans[t1++]=arr[p][5];
            }
            else{
                rotate(arr[p][5]+6);
                rotate(5);
                rotate(arr[p][5]);

                ans[t1++]=arr[p][5]+6; ans[t1++]=5; ans[t1++]=arr[p][5];
            } 
        }
        else if(vc1==sum(arr1[arr[p][2]],arr1[arr[p][0]],arr1[arr[p][4]])){
            if(ve1==sum(arr1[arr[p][0]],arr1[arr[p][1]],v)){
            rotate(arr[p][2]+6);
            rotate(11);
            rotate(arr[p][2]);

            ans[t1++]=arr[p][2]+6; ans[t1++]=11; ans[t1++]=arr[p][2];
            }
            else{
            rotate(arr[p][2]+6);
            rotate(5);
            rotate(arr[p][2]);

            ans[t1++]=arr[p][2]+6; ans[t1++]=5; ans[t1++]=arr[p][2];
            }
        }
        else if(vc1==sum(arr1[arr[p][3]],arr1[arr[p][0]],arr1[arr[p][4]])){
            if(ve1==sum(arr1[arr[p][5]],arr1[arr[p][1]],v)){
            rotate(arr[p][3]);
            rotate(11);
            rotate(arr[p][3]+6);

            ans[t1++]=arr[p][3]; ans[t1++]=11; ans[t1++]=arr[p][3]+6;
            }
            else{
            rotate(arr[p][3]);
            rotate(5);
            rotate(arr[p][3]+6);

            ans[t1++]=arr[p][3]; ans[t1++]=5; ans[t1++]=arr[p][3]+6;
            }
        }
    }  

    vc1 = matrixes[p][6].v1;
    vc2 = matrixes[p][6].v2;
    ve1 = matrixes[p][2].v1;
    ve2 = matrixes[p][2].v2;

    if(vc1[2]==-1 || ve1[2]!=1){
        cout<<"wrong2"<<endl;
    }

    if(vc1==sum(arr1[arr[p][3]],arr1[arr[p][5]],arr1[arr[p][1]])){
        //cout<<"true"<<endl;
        rotate(5);
        ans[t1++]=5;
    }
    if(vc1==sum(arr1[arr[p][2]],arr1[arr[p][0]],arr1[arr[p][1]])){
        //cout<<"t"<<endl;
        rotate(11);
        ans[t1++]=11;
    }
    if(vc1==sum(arr1[arr[p][2]],arr1[arr[p][5]],arr1[arr[p][1]])){
        //cout<<"L"<<endl;
        rotate(5);
        rotate(5);
        ans[t1++]=5; ans[t1++]=5;
    }

        vc1 = matrixes[p][6].v1;
        vc2 = matrixes[p][6].v2;
        ve1 = matrixes[p][2].v1;
        ve2 = matrixes[p][2].v2;
        if(vc1[2]==-1 || ve1[2]!=1){
            cout<<"wrong3"<<endl;
    }

    vector<int> vw2;
    if(p==1) vw2 =matrixes[0][5].v2;
    else if(p==2) vw2 =matrixes[0][6].v2;
    else if(p==3) vw2 =matrixes[0][8].v2;
    else vw2 =matrixes[0][7].v2;

    dostep2(p,vc1,vc2,ve1,ve2,v,vw2,ans,t1);
    
}

//TO IMPLEMENT F2L ALGORITHM
void implementF2L(){
    vector<int> answer(100);
    vector<int> tmp_ans(100);
    int anslen=100 , templen=0;
    for(int i=1; i<5 ; i++){
        for(int j=1 ; j<5 ; j++){
            for(int k=1 ; k<5 ; k++){
                for(int l=1 ; l<5 ;l++){
                    if(!(i==j || i==k || i==l || j==k || j==l || k==l)){

                        templen=0;
                        copy1();
                        
                        place2(i,tmp_ans , templen); 
                        place2(j,tmp_ans , templen); 
                        place2(k,tmp_ans , templen); 
                        place2(l,tmp_ans , templen); 

                        if(anslen>templen){
                            anslen=templen;
                            for(int c=0 ; c<templen ; c++){
                                answer[c]=tmp_ans[c];
                            }
                        }

                        copy2();
                    }

                }
            }
        }
    }
     
    totalSteps+=anslen;
    cout<<"Total Steps for F2L: "<<anslen<<"\n";
    for(int m=0 ; m<anslen; m++){
        cout<<answer[m]<<" ";
        rotate(answer[m]);
    }
    cout<<endl;
    cout<<"Total Steps till F2L: "<<totalSteps<<endl;
}

//TO IMPLEMENT OLL ALGORITHM
void oll(){

    cout<<"\nSteps for OLL:\n";
    createFaces();

    int m=0;
    vector<int> arrr;
    vector<int> vc ={yellow[0][2] , yellow[2][2] , yellow[2][0] , yellow[0][0]};

    for(int i=0 ; i<4 ; i++){
        if(vc[i]==5){
            m++; 
            arrr.push_back(i+5);
        }
    }

    if(m==1){
        int p;
        bool n;
        //cout<<"m1"<<endl;
        if(arrr[0]==5 && orange[0][2]==5) {p=1; n =true;}
        else if(arrr[0]==6 && orange[0][2]==5) {p=3; n=true;}
        else if(arrr[0]==7 && orange[0][2]==5) {p=4; n = true;}
        else if(arrr[0]==8 && blue[0][2]==5) {p=2; n =true;}
        else if(arrr[0]==5 && blue[0][0]==5) {p=3; n =false;}
        else if(arrr[0]==6 && blue[0][0]==5) {p=4; n=false;}
        else if(arrr[0]==7 && blue[0][0]==5) {p=2; n = false;}
        else if(arrr[0]==8 && blue[0][0]==5) {p=1; n =false;}
        
        if(n==true){
            //cout<<1<<endl;
            rotate(arr[p][2]);rotate(arr[p][1]);rotate(arr[p][2]+6);rotate(arr[p][1]);rotate(arr[p][2]);
            rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][2]+6);

            cout<<arr[p][2]<<" "<<arr[p][1]<<" "<<arr[p][2]+6<<" "<<arr[p][1]<<" "<<arr[p][2]
            <<" "<<arr[p][1]<<" "<<arr[p][1]<<" "<<arr[p][2]+6;
            //y2
            totalSteps+=8;
        }
        
        if(n==false){
            //cout<<2<<endl;
            rotate(arr[p][3]+6);rotate(arr[p][1]+6);rotate(arr[p][3]);rotate(arr[p][1]+6);rotate(arr[p][3]+6);
            rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][3]);

            cout<<arr[p][3]+6<<" "<<arr[p][1]+6<<" "<<arr[p][3]<<" "<<arr[p][1]+6<<" "<<arr[p][3]+6
            <<" "<<arr[p][1]<<" "<<arr[p][1]<<" "<<arr[p][3];
            totalSteps+=8;
        }

    }
    
    else if(m==0){
        //cout<<"m0"<<endl;
        int p;
        bool n;
        if(orange[0][0]==5 && orange[0][2]==5 && red[0][0]==5 && red[0][2]==5 ){
            p=1; n=true;
        }
        else if(blue[0][0]==5 && blue[0][2]==5 && green[0][0]==5 && green[0][2]==5 ){
            p=2; n=true;
        }
        else if(blue[0][0]==5 && blue[0][2]==5 && red[0][2]==5 && orange[0][0]==5 ){
            p=1; n=false;
        }
        else if(red[0][0]==5 && red[0][2]==5 && blue[0][0]==5 && green[0][2]==5 ){
            p=2; n=false;
        }
        else if(green[0][0]==5 && green[0][2]==5 && red[0][0]==5 && orange[0][2]==5 ){
            p=4; n=false;
        }
        else if(orange[0][0]==5 && orange[0][2]==5 && green[0][0]==5 && blue[0][2]==5 ){
            p=3; n=false;
        }

        if(n==true){
            //cout<<3<<endl;
            rotate(arr[p][3]);rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][3]+6);rotate(arr[p][1]+6);
            rotate(arr[p][3]);rotate(arr[p][1]);rotate(arr[p][3]+6);rotate(arr[p][1]+6);rotate(arr[p][3]);rotate(arr[p][1]+6);rotate(arr[p][3]+6);

            cout<<arr[p][3]<<" "<<arr[p][1]<<" "<<arr[p][1]<<" "<<arr[p][3]+6<<" "<<arr[p][1]+6
            <<" "<<arr[p][3]<<" "<<arr[p][1]<<" "<<arr[p][3]+6<<" "<<arr[p][1]+6<<" "<<arr[p][3]<<" "<<arr[p][1]+6<<" "<<arr[p][3]+6;
            totalSteps+=12;
        }
        if(n==false){
            //case 22
            rotate(arr[p][3]);rotate(arr[p][1]+6);rotate(arr[p][1]+6);rotate(arr[p][3]);rotate(arr[p][3]);
            rotate(arr[p][1]+6);rotate(arr[p][3]);rotate(arr[p][3]);rotate(arr[p][1]+6);
            rotate(arr[p][3]);rotate(arr[p][3]);rotate(arr[p][1]+6); rotate(arr[p][1]+6); rotate(arr[p][3]);

            cout<<arr[p][3]<<" "<<arr[p][1]+6<<" "<<arr[p][1]+6<<" "<<arr[p][3]<<" "<<arr[p][3]
            <<" "<<arr[p][1]+6<<" "<<arr[p][3]<<" "<<arr[p][3]<<" "<<arr[p][1]+6
            <<" "<<arr[p][3]<<" "<<arr[p][3]<<" "<<arr[p][1]+6<<" "<<arr[p][1]+6<<" "<<arr[p][3]; 
            totalSteps+=14;
        }
    }

    else if(m==2){
        //cout<<"m2"<<endl;
        int n; int p;
        if(blue[0][0]==5 && blue[0][2]==5 ){
            p=3; n=1;
        }
        else if(red[0][0]==5 && red[0][2]==5 ){
            p=1; n=1;
        }
        else if(green[0][0]==5 && green[0][2]==5 ){
            p=2; n=1;
        }
        else if(orange[0][0]==5 && orange[0][2]==5 ){
            p=4; n=1;
            //cout<<"true"<<endl;
        }
        else if(red[0][0]==5 && green[0][2]==5 ){
            p=1; n=2;
        }
        else if(green[0][0]==5 && orange[0][2]==5 ){
            p=2; n=2;
        }
        else if(orange[0][0]==5 && blue[0][2]==5 ){
            p=4; n=2;
        }
        else if(blue[0][0]==5 && red[0][2]==5 ){
            p=3; n=2;
        }
        else if(orange[0][0]==5 && red[0][2]==5 ){
            p=1; n=3;
        }
        else if(blue[0][0]==5 && green[0][2]==5 ){
            p=2; n=3;
        }
        else if(red[0][0]==5 && orange[0][2]==5 ){
            p=4; n=3;
            //cout<<false;
        }
        else if(green[0][0]==5 && blue[0][2]==5 ){
            p=3; n=3;
        }
        //cout<<"entering"<<endl;
        
        if(n==1){
            //case 23
            //cout<<5<<endl;
            rotate(arr[p][3]);rotate(arr[p][3]);rotate(arr[p][4]);rotate(arr[p][3]+6);rotate(arr[p][1]);
            rotate(arr[p][1]);rotate(arr[p][3]);rotate(arr[p][4]+6);rotate(arr[p][3]+6);
            rotate(arr[p][1]);rotate(arr[p][1]);rotate(arr[p][3]+6);

            cout<<arr[p][3]<<" "<<arr[p][3]<<" "<<arr[p][4]<<" "<<arr[p][3]+6<<" "<<arr[p][1]
            <<" "<<arr[p][1]<<" "<<arr[p][3]<<" "<<arr[p][4]+6<<" "<<arr[p][3]+6
            <<" "<<arr[p][1]<<" "<<arr[p][1]<<" "<<arr[p][3]+6;
            totalSteps+=12;
        }
        if(n==2){ 
            // case 25
            //cout<<6<<endl;
            rotate(arr[p][3]+6);rotate(arr[p][0]);rotate(arr[p][3]);rotate(arr[p][5]+6);rotate(arr[p][3]+6);
            rotate(arr[p][0]+6);rotate(arr[p][3]);rotate(arr[p][5]);

            cout<<arr[p][3]+6<<" "<<arr[p][0]<<" "<<arr[p][3]<<" "<<arr[p][5]+6<<" "<<arr[p][3]+6
            <<" "<<arr[p][0]+6<<" "<<arr[p][3]<<" "<<arr[p][5];
            totalSteps+=8;    
            }
        if(n==3){
            //cout<<7<<endl;
            // case 24
            rotate(arr[p][3]);rotate(arr[p][5]);rotate(arr[p][2]+6);rotate(arr[p][5]+6);rotate(arr[p][3]+6);
            rotate(arr[p][5]);rotate(arr[p][2]);rotate(arr[p][5]+6);

            cout<<arr[p][3]<<" "<<arr[p][5]<<" "<<arr[p][2]+6<<" "<<arr[p][5]+6<<" "<<arr[p][3]+6
            <<" "<<arr[p][5]<<" "<<arr[p][2]<<" "<<arr[p][5]+6;
            totalSteps+=8;
            }
    }
    
    
}

//TO CHECK FOR YELLOW CROSS
bool checkYellowCross(){
    
    createFaces();

    if (yellow[0][1]==5 && yellow[1][0]==5 && yellow[1][2]==5 && yellow[2][1]==5 ) return true;
    return false;
}

//TO CREATE YELLOW CROSS
void createYellowCross(){
    
    cout<<"\nSteps for Yellow Cross:\n";
    int cnt=0;
    while(!checkYellowCross()){

        cnt++;
        createFaces();

        int p=4;
        if (yellow[1][0]==5 && yellow[1][1]==5 && yellow[1][2]==5){
            p=4;
        }
        else if (yellow[0][1]==5 && yellow[1][1]==5 && yellow[2][1]==5){
            p=3;
        }
        else if (yellow[0][1]==5 && yellow[1][1]==5 && yellow[1][0]==5){
            p=4;
        }
        else if (yellow[0][1]==5 && yellow[1][1]==5 && yellow[1][2]==5){
            p=2;
        }
        else if (yellow[1][0]==5 && yellow[1][1]==5 && yellow[2][1]==5){
            p=3;
        }
        else if (yellow[1][2]==5 && yellow[1][1]==5 && yellow[2][1]==5){
            p=1;
        }

        rotate(arr[p][0]); rotate(arr[p][3]); rotate(arr[p][1]); rotate(arr[p][3]+6); rotate(arr[p][1]+6); rotate(arr[p][0]+6);
        cout<<arr[p][0]<<" "<<arr[p][3]<<" "<<arr[p][1]<<" "<<arr[p][3]+6<<" "<<arr[p][1]+6<<" "<<arr[p][0]+6;
        
    }

    totalSteps+=6;
    cout<<"\nYellow Cross made in "<<cnt*6<<" moves"<<endl;
}

//TO SET CORNERS
void setCorners(){
    createFaces();

    if (red[0][2]==1 && green[0][0]==2 && green[0][2]==2 && orange[0][0]==4 && orange[0][2]==4 && blue[0][0]==3 && blue[0][2]==3 && red[0][0]==1) return;

    while(true){
        createFaces();

        if (red[0][2]==1 && green[0][0]==2 && green[0][2]==2 && orange[0][0]==4 && orange[0][2]==4 && blue[0][0]==3 && blue[0][2]==3 && red[0][0]==1) break;
        else{
            int p=0;
            if ((red[0][2]==1 && green[0][0]==2) && (red[0][0]==1 && blue[0][2]==3)) p=4;
            else if ((red[0][2]==1 && green[0][0]==2) && (green[0][2]==2 && orange[0][0]==4)) p=3;
            else if ((green[0][2]==2 && orange[0][0]==4) && (blue[0][0]==3 && orange[0][2]==4)) p=1;
            else if ((blue[0][0]==3 && orange[0][2]==4) && (blue[0][2]==3 && red[0][0]==1)) p=2;
            else if ((red[0][0]==1 && blue[0][2]==3) && (green[0][2]==2 && orange[0][0]==4)) p=4;
            else if ((blue[0][0]==3 && orange[0][2]==4) && (green[0][0]==2 && red[0][2]==1)) p=4;
            
            if(p){
                rotate(arr[p][3]+6);rotate(arr[p][0]);rotate(arr[p][3]+6);rotate(arr[p][5]);rotate(arr[p][5]);
                rotate(arr[p][3]);rotate(arr[p][0]+6);rotate(arr[p][3]+6);rotate(arr[p][5]);rotate(arr[p][5]);
                rotate(arr[p][3]);rotate(arr[p][3]);rotate(arr[p][1]+6);

                cout<<arr[p][3]+6<<" "<<arr[p][0]<<" "<<arr[p][3]+6<<" "<<arr[p][5]<<" "<<arr[p][5]
                <<" "<<arr[p][3]<<" "<<arr[p][0]+6<<" "<<arr[p][3]+6<<" "<<arr[p][5]<<" "<<arr[p][5]
                <<" "<<arr[p][3]<<" "<<arr[p][3]<<" "<<arr[p][1]+6<<" ";
                totalSteps+=13;
            }
            else{
                rotate(5);
                cout<<"5 ";
                totalSteps+=1;
            }

        }
    }
    cout<<endl;
}

//TO SET EDGES
void setEdges(){
    createFaces();

    if (green[0][1]==2 && red[0][1]==1 && blue[0][1]==3 && orange[0][1]==4) return;

    while(true){
        int p=1;
        int rotSense=0;
        createFaces();

        if (green[0][1]==2 && red[0][1]==1 && blue[0][1]==3 && orange[0][1]==4) break;
        else if (green[0][1]==2){
            p=3;
            if (blue[0][1]==4) rotSense=1;
        }
        else if (red[0][1]==1){
            p=4;
            if (orange[0][1]==2) rotSense=1;
        }
        else if (blue[0][1]==3){
            p=2;
            if (green[0][1]==1) rotSense=1;
        }
        else if (orange[0][1]==4){
            p=1;
            if (red[0][1]==3) rotSense=1;
        }

        
        if (rotSense){
            rotate(arr[p][0]);rotate(arr[p][0]);rotate(arr[p][1]);rotate(arr[p][2]);rotate(arr[p][3]+6);
            rotate(arr[p][0]);rotate(arr[p][0]);rotate(arr[p][2]+6);rotate(arr[p][3]);rotate(arr[p][1]);
            rotate(arr[p][0]);rotate(arr[p][0]);

            cout<<arr[p][0]<<" "<<arr[p][0]<<" "<<arr[p][1]<<" "<<arr[p][2]<<" "<<arr[p][3]+6
            <<" "<<arr[p][0]<<" "<<arr[p][0]<<" "<<arr[p][2]+6<<" "<<arr[p][3]<<" "<<arr[p][1]
            <<" "<<arr[p][0]<<" "<<arr[p][0]<<" ";
        }
        else{
            rotate(arr[p][0]);rotate(arr[p][0]);rotate(arr[p][1]+6);rotate(arr[p][2]);rotate(arr[p][3]+6);
            rotate(arr[p][0]);rotate(arr[p][0]);rotate(arr[p][2]+6);rotate(arr[p][3]);rotate(arr[p][1]+6);
            rotate(arr[p][0]);rotate(arr[p][0]);

            cout<<arr[p][0]<<" "<<arr[p][0]<<" "<<arr[p][1]+6<<" "<<arr[p][2]<<" "<<arr[p][3]+6
            <<" "<<arr[p][0]<<" "<<arr[p][0]<<" "<<arr[p][2]+6<<" "<<arr[p][3]<<" "<<arr[p][1]+6
            <<" "<<arr[p][0]<<" "<<arr[p][0]<<" ";
        }
        totalSteps+=12;
    }
    cout<<endl;
}

//TO CREATE LAST LAYER
void createLastLayer(){
    if (!checkYellowCross()){
        createYellowCross(); 
    }
    printAllFaces();
    cout<<"before oll"<<endl;
    oll();
    cout<<"\nafter oll"<<endl;
    printAllFaces();
    cout<<"Total Steps till OLL: "<<totalSteps<<endl;
    setCorners();
    cout<<"after setCorners()"<<endl;
    printAllFaces();
    cout<<"Total Steps till setting Corners: "<<totalSteps<<endl;
    setEdges();
    cout<<"after setEdges()"<<endl;
    printAllFaces();
    cout<<"Total Steps to solve the cube: "<<totalSteps<<endl;
}

//TO SHUFFLE THE CUBE
void shuffle(){
    int option=12;
    cout<<"\nEnter input for shuffling the cube\n";
    cout<<"Press 12 to exit\n";
    do{
        cin>>option;
        if (option<12)
            rotate(option);
    }
    while(option!=12);  
}

int main()
{
    createBlockMatrix();
    createFaceMatrix();
    shuffle();
    printAllFaces();
    makeWhiteCross();
    printAllFaces();
    implementF2L();
    printAllFaces();
    createLastLayer();
}