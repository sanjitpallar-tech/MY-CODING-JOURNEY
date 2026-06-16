# include<iostream>
using namespace std;

    class date 
    {
        private:
        int day, month, year;

        public:

        void getdata()
        {
            cout << "Enter the date"<<endl;
            cin>>day>>month;

        }
        void display()
        {
            cout << "Today's date="<<day<<"/";
            cout << month<<"/"<<year<<"/"<<endl;

        }
    };
    
    int main()
    {
        class date today;
        today.getdata();
        today.display();

        return 0;
    }