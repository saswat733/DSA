 int a[3][4]={{10,22,33,20},{1,39,44,30},{50,60,14,60}};         //method 1
int b[4][3];
 cout<<"before transpose"<<endl;
  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
}
 for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
        b[i][j]=a[j][i];
    }
 }
 cout<<"after transpose"<<endl;

 for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
        cout<<b[i][j]<<" ";
    }
    cout<<endl;
 }