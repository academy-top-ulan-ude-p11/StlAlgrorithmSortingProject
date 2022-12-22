#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class User
{
    string name;
    int age;
public:
    User(string name, int age) : name{ name }, age{ age } {}
    friend ostream& operator<<(ostream& out, const User& u)
    {
        out << "(" << u.name << ") - [" << u.age << "]";
        return out;
    }
    string& Name() { return name; }
    int& Age() { return age; }

    friend bool operator==(const User& u1, const User& u2)
    {
        return u1.name == u2.name;
    }

    friend bool operator<(const User& u1, const User& u2)
    {
        return u1.name < u2.name && u1.age < u2.age;
    }
};


int main()
{
    vector<User> users;
    users.push_back(User("Tim", 25));
    users.push_back(User("Jim", 19));
    users.push_back(User("Sam", 42));
    users.push_back(User("Ben", 36));
    users.push_back(User("Leo", 28));

    vector<int> v1{ 7, 6, 3, 5, 2, 4, 8, 9, 1 };
    //cout << boolalpha << is_sorted(v1.begin(), v1.end()) << "\n";

    //auto it = is_sorted_until(v1.begin(), v1.end());
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    /*auto it = partition(v1.begin(), v1.end(),
        [](auto item) { return item % 2; });
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";*/

    nth_element(v1.begin(), v1.begin() + 3, v1.end());
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    /*
    cout << is_sorted(users.begin(), users.end()) << "\n";

    sort(users.begin(), users.end(), 
        [](User u1, User u2) { return u1.Age() < u2.Age(); });
    
    for_each(users.begin(), users.end(), 
        [](auto item) {cout << item << "\n"; });
    cout << "\n";
    */

}
