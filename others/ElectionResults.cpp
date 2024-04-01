#include <iostream>
#include <climits>
using namespace std;
int main(){
    const int noOfBoothms=5;//booths
    const int noOfCan=4;//cans
    int arr[noOfBoothms][noOfCan] = {
        {192,48,206,37},
        {147,90,321,21},
        {186,12,121,38},
        {114,21,408,39},
        {267,13,982,29}
    };

    int totalVotes=0;
    for(int i=0;i<noOfBoothms;i++){
        for(int j=0;j<noOfCan;j++){
            totalVotes+=arr[i][j];
        }
    }

    cout<<"Toatl Votes: "<<totalVotes<<endl;
    int candidateVotes[noOfCan];

    // o(n,m) so lineaer
    for(int can=0;can<noOfCan;can++){
        int canVotes=0;
        for(int booth=0;booth<noOfBoothms;booth++){
            canVotes+=arr[booth][can];
        }
        cout<<"candidate: "<<can<<" : "<<canVotes<<endl;
        candidateVotes[can]=canVotes;
    }

    bool flag=false;
    for(int i=0;i<noOfCan;i++){
        double votePer = static_cast<double>(candidateVotes[i]) / totalVotes;
        votePer*=100;
        if(votePer>50){
            cout<<"Winner : "<<i<<endl;
            // flag=true;
        }
    }

    if(!flag){
        int largest=INT_MIN;
        int slargest=INT_MIN;
        int largestIndex=-1;
        int slargestIndex=-1;

        for(int i=0;i<noOfCan;i++){
            if(candidateVotes[i]>largest){
                slargest=largest;
                slargestIndex=largestIndex;
                largest=candidateVotes[i];
                largestIndex=i;
            }else if (candidateVotes[i]>slargest){
                slargest=candidateVotes[i];
                slargestIndex=i;
            }
        }
        cout<<"Top Two Winners:-"<<endl;
        cout<<largestIndex<<" "<<slargestIndex<<endl;
    }

    return 0;
}