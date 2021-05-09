#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>  //  toupper()

#include "LinkedListADT.h"
#include "College.h"


using namespace std;

void buildList(const string &filename, LinkedList<College> &list);
void deleteManager(LinkedList<College> &list);
void searchManager(const LinkedList<College> &list);
void displayManager(const LinkedList<College> &list);

int main()
{

    string inputFileName = "colleges.txt";
    LinkedList<College> list;

    buildList(inputFileName, list);
    displayManager(list);
    searchManager(list);
    deleteManager(list);
    displayManager(list);
    return 0;
}

/* 
 This function reads data about colleges from a file and inserts them
 into a sorted linked list. The list is sorted in ascending order by code
 */
void buildList(const string &filename, LinkedList<College> &list)
{
    ifstream fin(filename);
    cout << "Reading data from \"" << filename << "\"";

    if(!fin)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(fin, line))
    {
       int rank, cost;
       string code, name;
    
       stringstream temp(line);   // create temp with data from line
       temp >> rank;              // read from temp
       temp >> code;
       temp.ignore();             // to ignore space in front of name
       getline(temp, name, ';');  // stop reading name at ';'
       temp >> cost;
       // create a College object and initialize it with data from file
       College aCollege(rank, code, name, cost);
       list.insertNode(aCollege);
    }

    fin.close();
}

/* 
 Delete manager: delete items from the list until the user enters Q to quit
 deleting
 Input Parameter: list
 */
void deleteManager(LinkedList<College> &list)
{
    string targetCode = "";

    cout << "\n Delete\n";
    cout << "=======\n";

    while(toupper(targetCode[0]) != 'Q')
    {
        cout << endl << "Enter a college code (or Q to stop deleting) : \n";
        cin >> targetCode;
        cout << endl;

        if(toupper(targetCode[0]) != 'Q')
        {
            College target;
            target.setCode(targetCode);
            if(list.deleteNode(target))
                cout << targetCode << " has been deleted!\n";
            else
                cout << "College \"" << targetCode << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END DELETE SECTION_____\n";
}

/* 
 Search manager: search the list until the user enters Q to quit searching
 Input Parameter: list
 */
void searchManager(const LinkedList<College> &list)
{
    string targetCode = "";
    College aCollege;

    cout << "\n Search\n";
    cout <<   "=======\n";

    while(toupper(targetCode[0]) != 'Q')
    {
        cout << "\nEnter a college code (or Q to stop searching) : \n";
        cin >> targetCode;

        if(toupper(targetCode[0]) != 'Q')
        {
            College target;
            target.setCode(targetCode);
            if(list.searchList(target, aCollege))
                aCollege.vDisplay();
            else
                cout << "College \"" << targetCode << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END SEARCH SECTION _____\n";
}

/* 
Display manager: diplay a header, formatted list content, and footer,
 depending on the user's choice;
 displays the number of nodes (always)
Input Parameter: list
 */
void displayManager(const LinkedList<College> &list)
{
    string action;
    
    cout << "\nDisplay list [F/B/N]? ";
    cin >> action;
    char option = toupper(action[0]);
    
    if (option == 'F' || option == 'B')
    {
        cout << "\n====== ==== ============================= =========\n"
             << " Code  Rank         Name                     Cost  \n"
             << "====== ==== ============================= =========\n";
        
        if (option == 'F')
            list.displayListForw();
        else
            list.displayListBack();
        
        cout << "====== ==== ============================= =========\n";
        cout << "Number of colleges in this list: " << list.getLength() << endl;
    }
}
