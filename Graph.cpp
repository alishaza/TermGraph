#include <iostream>
#include <vector>
#include <string>
using namespace std;



struct status {
    double frequency;
    string value;
};


void loadingBar(int progress , int end )
{
	printf("\t");
	char a = 177, b = 219;
	for (int i = 0; i < end; i++)
		printf("%c", a);
    printf("\r");
    printf("\t");
	for (int i = 0; i < progress; i++) {
 	 printf("%c", b);
	}
}

void ChartPrint (vector <status> Data)
{
   cout << "element\t    Percent" << endl << "==========================="<< endl;
    double sum = 0 ; 
    for ( auto i = Data.begin() ; i != Data.end() ; i++ )
    {
        sum += i->frequency;
       
    }
    for ( auto i = Data.begin() ; i != Data.end() ; i++ )
    {
       
        double percent= ((i->frequency)/sum)*100;
        cout << i->value   <<  "  "  ;
        loadingBar((int)(percent/10) , 10 );
        cout << "\t  " <<   (float)percent << "%" ; 
        cout << endl << endl ;
    }
  
} 




int main () 
{
  

    system("Color 0B");
     //loadingBar(10 ,2);
    vector <status> Data ;
    string element ;
    bool flag = true ; 
 
    while (1){
        getline(cin,element);
        if ( element.empty())
        break;
        for( auto i = Data.begin() ; i != Data.end() ; i++)
        {
            if ( i->value == element)
            {
                i->frequency++;
                flag=false;
                break;
                
            }
        }
        if (flag){
        status p ;
        p.value = element;
        p.frequency=1;
        Data.push_back(p);
        }
        else { 
            flag = true ;
        }
        
    }

    ChartPrint(Data);

}

