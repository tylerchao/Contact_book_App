//storing, editing, searching, and deleting contact information
#include <iostream>
#include <vector>

struct Contact
{
    std::string name;
    std::string email;
    std::string phone;
};

void display_data(const std::vector<Contact> &contact_book){
    
    if (contact_book.size()==0) {
        std::cout << "currently there are no datas" << std::endl;
    }


    for (const auto &contact : contact_book){
      std::cout << "name: "<<contact.name <<std::endl<< "email: " << contact.email <<std::endl<< "phone: " << contact.phone << std::endl;
    }  

}

void adding_data(std::vector<Contact> &contact_book, std::string name, std::string email, std::string phone){

    Contact new_contact;
    new_contact.name = name;
    new_contact.email = email;
    new_contact.phone = phone;

    contact_book.push_back(new_contact);

}

void searching_data(const std::vector<Contact> &contact_book,const std::string searching_name){

    int index = -1;

    for (int i =0; i < contact_book.size() ; i++){
        if (contact_book[i].name == searching_name) {
            index = i ;
            break;
        }

    }

    if(index  == -1){
        std::cout << "No find any data......" << std::endl;
    }else{
         std::cout << "name: "<<contact_book[index].name <<std::endl
                   << "email: " << contact_book[index].email <<std::endl
                   << "phone: " << contact_book[index].phone << std::endl;
    }

}

void deleting_data(std::vector<Contact> &contact_book,std::string deleting_name){

    int index = -1;

    for (int i =0; i < contact_book.size() ; i++){
        if (contact_book[i].name == deleting_name) {
            index = i ;
           
            break;
        }

    }

    if(index  == -1){
        std::cout << "No find any data......" << std::endl;
    }else{
        contact_book.erase(contact_book.begin()+index);
    
        std::cout << "Data has been removed from our system" <<std::endl;
    }

}


int main(){
    int number;
    std::string input_name, input_email, input_phone;
    std::vector<Contact> contact_book;
    bool system_running = true;

    while(system_running){
    std::cout << "Welcome to contact application system !!!!!!" << std::endl;

    std::cout << "1. Display all contact information "<<  std::endl
              << "2. Searching data" << std::endl
              << "3. Add a contact " << std::endl
              << "4. Deleting a contact " << std::endl
              << "5. End the system " << std:: endl;

    std::cout << "Please press a number " << std::endl;

    std::cin >> number ;

    switch (number)
    {
    case 1:
        display_data(contact_book);
        break;
    
    case 2:
        std::cout << "Please enter a name for searching " << std::endl;

        std::cin >> input_name ;

        searching_data(contact_book,input_name);
        break;
    
    case 3:
        std::cout << "Please enter a name  ";

        std::cin >> input_name ;
        std::cout << "Please enter a email address  ";

        std::cin >> input_email ;
        std::cout << "Please enter a phone number " ;
        std::cin >> input_phone ;

        adding_data(contact_book,input_name,input_email,input_phone);
        break;
    
    case 4:
        std::cout << "Please enter a name " << std::endl;

        std::cin >> input_name ;

       deleting_data(contact_book,input_name);
        break;
    
    case 5:
        std::cout << "Thank your for visiting our contact system " << std::endl;
        system_running = false;
        break;
    default:
        std::cout << "Please enter a valid number " << std::endl;
        break;
    }

    }
   

}
