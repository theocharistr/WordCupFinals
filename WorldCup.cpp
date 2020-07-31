#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set> 
using namespace std;

bool sortbysec(const pair<string,int> &a, 
              const pair<string,int> &b) 
{ 
    return (a.second > b.second); 
} 
  
int main(){

  ifstream ip("WorldCupFinals.csv");

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  vector <string>  Year;
  vector <string>  Winner;
  vector <string>  Score;
  vector <string>  Runnerup;
  vector <string>  Venue;
 
  string year;
  string winner;
  string score;
  string runnerup;
  string venue;	
  
  while(ip.good()){

    getline(ip,year,',');
    Year.push_back(year);
    getline(ip,winner,',');
    Winner.push_back(winner);
    getline(ip,score,',');
    Score.push_back(score);
    getline(ip,runnerup,',');
	Runnerup.push_back(runnerup);
    getline(ip,venue,'\n');
	Venue.push_back(venue);


    std::cout << "Year: "<<year<< '\n';
    std::cout << "Winner: "<<winner << '\n';
    std::cout << "Score: "<<score << '\n';
    std::cout << "Runner-up: "<<runnerup << '\n';
    std::cout << "Venue: "<<venue << '\n';
    

    std::cout << "-------------------" << '\n';
  }
  
	replace(Winner.begin(), Winner.end(), string{"West Germany"}, string{"Germany"});
	replace(Runnerup.begin(), Runnerup.end(), string{"West Germany"}, string{"Germany"});
 
 
	vector<string>::iterator iter = Winner.begin();

         while (iter != Winner.end())
        {
                if((*iter == "Editions not played because of World War II.") ||(*iter=="Winners"))
                      iter = Winner.erase(iter);
                else
                      iter++;
        }

	sort(Winner.begin(), Winner.end()); 
	vector  <int> counter;
	vector< pair <string, int> > vect; 
	
	for(int i=1;i< Winner.size(); i++){
		if ( Winner[i]!=Winner[i+1])	
		{  
			vect.push_back( make_pair(Winner[i],count(Winner.begin(), Winner.end(),Winner[i])) ); 
		}
	}		
 
 
	sort(vect.begin(), vect.end(),sortbysec); //Sorting the countries based on the times they have own the world cup
	ofstream myFile;
	myFile.open("Winners.csv"); //Save my data to Winners.csv
	for (int i=0; i<Winner.size(); i++) 
    { 
        // "first" and "second" are used to access 
        // 1st and 2nd element of pair respectively 
       cout <<vect[i].first << " has won the world cup:"
        << vect[i].second << endl; 
    
	myFile <<vect[i].first<<","<<vect[i].second<<endl;
	} 
}

 
	
	
	

