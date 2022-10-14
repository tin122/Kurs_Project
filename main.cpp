/******************************************************************************
Разработка программно-информационной системы «Вакцинированные от Covid-19»
*******************************************************************************/
#include <iostream>  // Операции ввода/вывода
#include <fstream>   //чтения/записи данных из/в файл
#include <list>      // двусвязные списки
#include <string>    // использование строк
#include <cstdlib>   // стандарт библиотека
#include <algorithm> // для алгоритмического управления контейнерами и т.д.
#include <iomanip>   // управление выводом

#define Console_cout cout << "| № | Фамилия |     Имя     |  Отчество  | Год рождения | Привился | Самочуствие пациента" << endl << endl;
#define Pacient_cout cout << "|" << setw(2)<< v.Nomer << " | "<<  v.F << "  |" << v.I <<" | "<< v.O << " | " << v.God << " | " << v.Privilsya << " | " << v.otenka << " | " << endl;
using namespace std; // пространство имен


ofstream fout; // класс, запись данных в файл
ifstream fin;  // класс, чтение данных из файла 

//обьединим данные в структуру
struct Pacient
{
    string Nomer;
    string F;
    string I;
    string O;
    string God;
    string Privilsya;
    int otenka;
};

void clear_console() // очистка консоли
{
    if (system("clear"))
        system("cls");
};


void pause_console()
{
    char a[100];
    cout << "Для продолжения нажмите enter . . . ";
    cin.ignore();
    cin.getline(a, 255);
    clear_console();
}

// Делаем сортировку по оценке;
bool compare(const Pacient& a, const Pacient& b)
{
    return a.otenka > b.otenka;
}

//База данных
list<Pacient> dbase;

//Описываем функции, которые будут вызываться при выборе пункта меню

void save_file()
{

    fout.open("Base.txt", ios_base::trunc);
    fout << dbase.size() << endl;
    for (Pacient v : dbase)
    {
        fout << v.Nomer << endl;
        fout << v.F << endl;
        fout << v.I << endl;
        fout << v.O << endl;
        fout << v.God << endl;
        fout << v.Privilsya << endl;
        fout << v.otenka << endl;
    }
    fout.close();
    clear_console();
    cout << "База данных успешно сохранена!\n";
}

bool load_file()
{
    Pacient v;
    int help = 0;

    fin.open("Base.txt");

    if (!fin)
    {
        fin.close();
        return false;
    }

    fin >> help;

    for (int i = 0; i < help; i++)
    {
        fin >> v.Nomer;
        fin >> v.F;
        fin >> v.I;
        fin >> v.O;
        fin >> v.God;
        fin >> v.Privilsya;
        fin >> v.otenka;

        dbase.push_back(v);
    }
    fin.close();

    if (dbase.empty())
    {
        return false;
    }

    return true;
}

//Пункт ввод в базу
void insert_base()
{
    Pacient st;
    cout << "Введите номер пациента: ";
    cin >> st.Nomer;     cout << endl;
    cout << "Введите Фамилию пациента: ";
    cin >> st.F;       cout << endl;
    cout << "Введите Имя пациента: ";
    cin >> st.I;       cout << endl;
    cout << "Введите Отчество пациента: ";
    cin >> st.O;       cout << endl;
    cout << "Введите год рождения пациента: ";
    cin >> st.God;       cout << endl;
    cout << "Пациент привился: ";
    cin >> st.Privilsya; cout << endl;
    cout << "Самочуствие пациента: ";
    cin >> st.otenka;    cout << endl;
    dbase.push_back(st);
    save_file();
};
//Пункт "Печать базы"
void print_base()
{
    Console_cout;
    
    for (Pacient v : dbase) {
        
        Pacient_cout;
        
    }
    cout << endl;
    pause_console();
    clear_console();
};

//Пункт "Сортировка данных в базе"
void sort_base() {
    dbase.sort(compare);
    save_file();
    cout << "База данных успешно отсортирована!" << endl << endl;
};
 
//Пункт "Поиск по критерию" ----------------------------------------------------
void find()
{
    bool findP = false;
    string query;
    int sort_menu;
    Pacient v;
    //cout << "Поиск пациента по базе\n\n Введите способ поиска: ";
    
    //-----выбор способа поиска ----------------
    cout << "Поиск пациента по базе: \n\
                     1. По фамилии \n\
                     2. Год \n\
                     3. Прививка \n ";

    cin >> sort_menu ;
    //Проверяем на "правильность"
        if (sort_menu < 1 || sort_menu > 3)
        {
            cout << "Неверный выбор!\n";
        }
        else
        {
            cout << "Введите данные по поиску\n";
            
            switch (sort_menu)
            {
                
            case 1: // По фамилии
            {
                string query;
                bool findP;
                cin >> query; cout << endl;
                clear_console();
                cout << "Поиск пациента по базе\n\n";
                for (Pacient v : dbase) 
                {
                    if (v.F == query) 
                    {
                        Pacient_cout;
                        findP = true;
                    }
                }
            
             if (!findP)
             {
                 clear_console();
                 cout << "Поиск пациента по базе\n\n";
                 cout << "В базе данных не было обнаруженно данного пациента!" << endl << endl;
             }
             pause_console();
             clear_console();
            }
            
            break; //---------------------------------------------------------------------------------
            case 2: // Год
            {
                string query;
                bool findP;
                cin >> query; cout << endl;
                clear_console();
                cout << "Поиск пациента по базе\n\n";
                for (Pacient v : dbase) 
                {
                    if (v.God == query) 
                    {
                        Pacient_cout;
                        findP = true;
                    }
                }
            
             if (!findP)
             {
                 clear_console();
                 cout << "Поиск пациента по базе\n\n";
                 cout << "В базе данных не было обнаруженно данного пациента!" << endl << endl;
             }
             pause_console();
             clear_console();
            }
            
           
            break; //---------------------------------------------------------------------------------
            case 3: // Прививка
            {
                string query;
                bool findP;
                cin >> query; cout << endl;
                clear_console();
                cout << "Поиск пациента по базе\n\n";
                for (Pacient v : dbase) 
                {
                    if (v.Privilsya == query) 
                    {
                        Pacient_cout;
                        findP = true;
                    }
                }
            
             if (!findP)
             {
                 clear_console();
                 cout << "Поиск пациента по базе\n\n";
                 cout << "В базе данных не было обнаруженно данного пациента!" << endl << endl;
             }
             pause_console();
             clear_console();
            }
           
            break;
            }
        }
};    
  

//---------------------------------------------------------------------------------
//Пункт "Удаление данных"
void remove_data() {
    bool success = false;
    string query;
    list<Pacient> ndb;
    cout << "Введите Фамилию пациента: ";
    cin >> query; cout << endl;
    for (Pacient v : dbase) {
        if (v.F != query) {
            ndb.push_back(v);
        }
        else
            success = true;
    }
    dbase = ndb;
    save_file();
    if (success)
        cout << "\nПациент " << query << " был удален!" << endl << endl;
    else
        cout << "\nПациент \"" << query << "\" не был найден!" << endl << endl;
};



// Пункт "Выход"
void exitp()
{
    exit(0);
};

// Начало
int main()
{
    (LC_ALL, "Russian");

    cout << "Здравсвуйте, вас приветствует программа для управления Базы Данных Пациентов\n\n";
    if (load_file())
        cout << "Пациенты были успешно загружены из базы данных!" << endl;
    else
        cout << "Не удалось загрузить пациентов из базы данных!" << endl;

    cout << endl;

    while (true)
    {
        //Массив указателей на функции - пункты меню
        void (*options[])() = { insert_base,
                                print_base,
                                sort_base,
                                find,
                                remove_data,
                                exitp };
        // edit_data,
        cout << "Выберите действие:\n\
                     1. Добавить в базу данных\n\
                     2. Просмотреть базу данных\n\
                     3. Сортировать базу\n\
                     4. Поиск в базе\n\
                     5. Удалить из базы\n\
                     6. Выход из программы\n > ";
        unsigned choise;
        cin >> choise;

        clear_console();

        //Проверяем выбор на "правильность"
        if (choise < 1 || choise > 6)
        {
            cout << "Неверный выбор!\n";
        }
        else
        {
            //Если выбор правильный, вызываем соответсвующий пункт
            options[choise - 1]();         // !!!
        }

    }
    return 0;
}
