#include<iostream>
using namespace std;
int main()
{
    cout<<"enter bucket size and out put rate";
    int bucket_size,output_rate,input_packet,choice;
    int filled = 0;
    cin>>bucket_size;
    cin>>output_rate;
    do{
        cout<<"\nenter packet size";
        cin>>input_packet;
        if(input_packet<=bucket_size){
            if(filled+input_packet > bucket_size){
                cout<<"\npackets are overflowing";

            }
            else{
                filled = filled + input_packet;
            }
        }
        else{
            cout<<"\nPacket overflowing";
            
        }
        if(filled <= output_rate)
            filled = 0;
        else {
            filled = filled - output_rate;
        }
        cout<<"\n amount of bucket fillled"<<filled;
        cout<<"\ndo you want to enter more? "<<endl;
        cin>> choice;
    }while(choice==1);
}