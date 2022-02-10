#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

struct student {

private:

	string name;
	int age;
	int group;
	vector<int> math;
	vector<int> phys;
	vector<int> info;
	vector<int> chem;

public:

	void set_name(string stud_name) {
		name = stud_name;
	}

	string get_name() {
		return name;
	}

	void set_age(int stud_age) {
		age = stud_age;
	}

	int get_age() {
		return age;
	}

	void set_group(int stud_group) {
		group = stud_group;
	}

	int get_group() {
		return group;
	}

	void set_math() {
		int u;
		u = 0;
		while (u == 0) {
			cout << "Введите оценку" << endl;
			int mark;
			cin >> mark;
			
			if (mark > -1 && mark < 11) {
				math.push_back(mark);
			}
			else {
				cout << "Ошибка" << endl;
			}
			cout << "Добавить оценку?   Да - 0   Нет - 1"  << endl;
			cin >> u;
		}
	}

	void set_phys() {
		int u;
		u = 0;
		while (u == 0) {
			cout << "Введите оценку" << endl;
			int mark;
			cin >> mark;
			
			if (mark > -1 && mark < 11) {
			phys.push_back(mark);
			}
			else {
				cout << "Ошибка" << endl;
			}

			cout << "Добавить оценку?   Да - 0   Нет - 1" << endl;
			cin >> u;
		}
	}

	void set_info() {
		int u;
		u = 0;
		while (u == 0) {
			cout << "Введите оценку" << endl;
			int mark;
			cin >> mark;
			
			if (mark > -1 && mark < 11) {
			info.push_back(mark);
			}
			else {
				cout << "Ошибка" << endl;
			}

			cout << "Добавить оценку?   Да - 0   Нет - 1" << endl;
			cin >> u;
		}
	}

	void set_chem() {
		int u;
		u = 0;
		while (u == 0) {
			cout << "Введите оценку" << endl;
			int mark;
			cin >> mark;
			
			if (mark > -1 && mark < 11) {
			chem.push_back(mark);
			}
			else {
				cout << "Ошибка" << endl;
			}

			cout << "Добавить оценку?   Да - 0   Нет - 1" << endl;
			cin >> u;
		}
	}

	void corr_math() {
		cout << endl;
		for (int i = 0; i < math.size(); i++) {
			cout << "[" << i << "] " << math[i] << " ";
		}
		
		cout << "Введите номер оценки" << endl;
		int num;
		cin >> num;
		if (num > -1 && num < 11) {
			math.erase(math.begin() + num);
		}
	}

	void corr_phys() {
		cout << endl;
		for (int i = 0; i < phys.size(); i++) {
			cout << "[" << i << "] " << math[i] << " ";
		}
		
		cout << "Введите номер оценки" << endl;
		int num;
		cin >> num;
		if (num > -1 && num < 11) {
			phys.erase(phys.begin() + num);
		}
	}

	void corr_chem() {
		cout << endl;
		for (int i = 0; i < chem.size(); i++) {
			cout << "[" << i << "] " << chem[i] << " ";
		}
		
		cout << "Введите номер оценки" << endl;
		int num;
		cin >> num;
		if (num > -1 && num < 11) {
			chem.erase(chem.begin() + num);
		}
	}

	void corr_info() {
		cout << endl;
		for (int i = 0; i < info.size(); i++) {
			cout << "[" << i << "] " << info[i] << " ";
		}
		
		cout << "Введите номер оценки" << endl;
		int num;
		cin >> num;
		if (num > -1 && num < 11) {
			info.erase(info.begin() + num);
		}
	}

	vector<int> get_math() {
		return math;
	}

	vector<int> get_phys() {
		return phys;
	}

	vector<int> get_info() {
		return info;
	}

	vector<int> get_chem() {
		return chem;
	}
	
	void set_math_file(int num) {
		if (num > 0 && num < 11) {
			math.push_back(num);
		}
	}

	void set_phys_file(int num) {
		if (num > 0 && num < 11) {
			phys.push_back(num);
		}
	}

	void set_info_file(int num) {
		if (num > 0 && num < 11) {
			info.push_back(num);
		}
	}

	void set_chem_file(int num) {
		if (num > 0 && num < 11) {
			chem.push_back(num);
		}
	}

	void set_name_file(string stud_name) {
		name = stud_name;
	}

	void set_age_file(int stud_age) {
		age = stud_age;
	}

	void set_group_file(int stud_group) {
		group = stud_group;
	}
};



int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream in("file.txt");

	if (in.is_open()){}
	else {
		cout << "Файл не открыт";
		return 0;
	}

	vector<student> stud;

	string name;
	int age;
	int group;
	

	while (1 == 1) {

		student curr;
		getline(in, name);
		if (name == "s") {
			
			break;
		}
		in >> age;
		in >> group;

		curr.set_name_file(name);
		curr.set_age_file(age);
		curr.set_group_file(group);

		int num;
		
		in >> num;
		while(num != -1) {
			curr.set_math_file(num);
			in >> num;
		}

		in >> num;
		while (num != -2) {
			curr.set_phys_file(num);
			in >> num;
		}

		in >> num;
		while (num != -3) {
			curr.set_info_file(num);
			in >> num;
		}

		in >> num;
		while (num != -4) {
			curr.set_chem_file(num);
			in >> num;
		}

		getline(in, name);
		stud.push_back(curr);
	}
	in.close();

	vector<int> math;
	vector<int> phys;
	vector<int> info;
	vector<int> chem;
	
	int o = 0;

	while (o == 0) {

		cout << endl << "Создание - 0    Просмотр - 1    Коррекция - 2    Задание - 3    Закончить - 4" << endl;
		int kod;
		cin >> kod;

		student curr;
		switch (kod) {

		case 0:
		{
			int y;
			y = 0;
			while (y == 0) {

				cout << "Введите имя и фамилию" << endl;
				string name;
				cin >> name;
				int age;

				cout << "Введите возраст" << endl;
				
				cin >> age;
				curr.set_name(name);
				curr.set_age(age);

				cout << "Введите номер группы" << endl;
				int group;
				cin >> group;
				curr.set_group(group);

				cout << "Математика:" << endl;
				curr.set_math();

				cout << "Физика:" << endl;
				curr.set_phys();

				cout << "Информатика:" << endl;
				curr.set_info();

				cout << "Химия:" << endl;
				curr.set_chem();

				stud.push_back(curr);
	
				cout << "Добавить студента?" << endl << " Да - 0   Нет - 1" << endl;
				cin >> y;

				ofstream out("file.txt");
				for (int i = 0; i < stud.size(); i++) {

					out << stud[i].get_name() << endl;
					out << stud[i].get_age() << endl;
					out << stud[i].get_group() << endl;

					math = stud[i].get_math();

					for (int j = 0; j < math.size(); j++) {
						out << math[j] << " ";
					}
					out << -1 << endl;

					phys = stud[i].get_phys();

					for (int j = 0; j < phys.size(); j++) {
						out << phys[j] << " ";
					}
					out << -2 << endl;

					info = stud[i].get_info();

					for (int j = 0; j < info.size(); j++) {
						out << info[j] << " ";
					}
					out << -3 << endl;

					chem = stud[i].get_chem();

					for (int j = 0; j < chem.size(); j++) {
						out << chem[j] << " ";
					}
					out << -4 << endl;

					if (i == stud.size() - 1) {
						out << "s";
					}
				}
				out.close();

			}
			break;
		}

		case 1:
		{

			for (int i = 0; i < stud.size(); i++) {

				cout << endl << "____________________________________________________________" << endl;
				cout << "Имя: " << stud[i].get_name() << endl;
				cout << "Возраст: " << stud[i].get_age() << endl;
				cout << "Группа: " << stud[i].get_group() << endl;

				math = stud[i].get_math();
				cout << "Математика" << endl;
				for (int i = 0; i < math.size(); i++) {
					cout << math[i] << " ";
				}
				cout << endl;

				phys = stud[i].get_phys();
				cout << "Физика" << endl;
				for (int i = 0; i < phys.size(); i++) {
					cout << phys[i] << " ";
				}
				cout << endl;

				info = stud[i].get_info();
				cout << "Информатика" << endl;
				for (int i = 0; i < info.size(); i++) {
					cout << info[i] << " ";
				}
				cout << endl;

				chem = stud[i].get_chem();
				cout << "Химия" << endl;
				for (int i = 0; i < chem.size(); i++) {
					cout << chem[i] << " ";
				}

			}
			cout << endl;
			break;
		}

		case 2:
		{
			cout << "Студенты:" << endl;

			for (int i = 0; i < stud.size(); i++) {
				cout << i << " " << stud[i].get_name() << endl;
			}

			cout << "Введите номер студента" << endl;

			int st;
			cin >> st;



			cout << "Выберите предмет" << endl << "Математика - 0   Физика - 1   Информатика - 2   Химия - 3" << endl;
			int subj;
			cin >> subj;
			int cor;

			switch (subj) {

			case 0:

				cout << endl << "Математика" << endl;
				cout << "Удалить оценку - 0    Добавить оценку - 1" << endl;
				cin >> cor;
				switch (cor) {

				case 0:
					stud[st].corr_math();
					break;

				case 1:
					stud[st].set_math();
					break;

				default:
					break;
				}
				break;

			case 1:

				cout << endl << "Физика" << endl;
				cout << "Удалить оценку - 0    Добавить оценку - 1" << endl;
				cin >> cor;
				switch (cor) {

				case 0:
					stud[st].corr_phys();
					break;

				case 1:
					stud[st].set_phys();
					break;

				default:
					break;
				}
				break;

			case 2:

				cout << endl << "Информатика" << endl;
				cout << "Удалить оценку - 0    Добавить оценку - 1" << endl;
				cin >> cor;
				switch (cor) {

				case 0:
					stud[st].corr_info();
					break;

				case 1:
					stud[st].set_info();
					break;

				default:
					break;
				}
				break;

			case 3:
			{
				cout << endl << "Химия" << endl;
				cout << "Удалить оценку - 0    Добавить оценку - 1" << endl;
				cin >> cor;
				switch (cor) {

				case 0:
					stud[st].corr_chem();
					break;

				case 1:
					stud[st].set_chem();
					break;

				default:
					break;
				}
				break;
			}
			}
			ofstream out("file.txt");
			for (int i = 0; i < stud.size(); i++) {

				out << stud[i].get_name() << endl;
				out << stud[i].get_age() << endl;
				out << stud[i].get_group() << endl;

				math = stud[i].get_math();

				for (int j = 0; j < math.size(); j++) {
					out << math[j] << " ";
				}
				out << -1 << endl;

				phys = stud[i].get_phys();

				for (int j = 0; j < phys.size(); j++) {
					out << phys[j] << " ";
				}
				out << -2 << endl;

				info = stud[i].get_info();

				for (int j = 0; j < info.size(); j++) {
					out << info[j] << " ";
				}
				out << -3 << endl;

				chem = stud[i].get_chem();

				for (int j = 0; j < chem.size(); j++) {
					out << chem[j] << " ";
				}
				out << -4 << endl;

				if (i == stud.size() - 1) {
					out << "s";
				}
			}
			out.close();

			break;
		}

		case 3:
		{
			vector<student> best;
			cout << "Введите группу" << endl;
			int gr;
			cin >> gr;

			for (int i = 0; i < stud.size(); i++) {

				if (stud[i].get_group() == gr) {

					vector<int> a;

					double aver;
					int sum = 0;
					int count = 0;
					int n = 0;

					a = stud[i].get_math();
					for (int j = 0; j < a.size(); j++) {
						sum += a[j];
					}
					aver = (double)sum / a.size();
					if (aver >= 9) {
						n++;
					}

					a = stud[i].get_phys();
					for (int j = 0; j < a.size(); j++) {
						sum += a[j];
					}
					aver = (double)sum / a.size();
					if (aver >= 9) {
						n++;
					}

					a = stud[i].get_info();
					for (int j = 0; j < a.size(); j++) {
						sum += a[j];
					}
					aver = (double)sum / a.size();
					if (aver >= 9) {
						n++;
					}

					a = stud[i].get_chem();
					for (int j = 0; j < a.size(); j++) {
						sum += a[j];
					}
					aver = (double)sum / a.size();
					if (aver >= 9) {
						n++;
					}

					if (n == 4) {
						best.push_back(stud[i]);
					}

				}

				ofstream out("best.txt");
				for (int i = 0; i < best.size(); i++) {

					out << best[i].get_name() << endl;
					out << best[i].get_age() << endl;
					out << best[i].get_group() << endl;

					math = best[i].get_math();

					for (int j = 0; j < math.size(); j++) {
						out << math[j] << " ";
					}
					out << endl;

					phys = best[i].get_phys();

					for (int j = 0; j < phys.size(); j++) {
						out << phys[j] << " ";
					}
					out << endl;

					info = best[i].get_info();

					for (int j = 0; j < info.size(); j++) {
						out << info[j] << " ";
					}
					out << endl;

					chem = best[i].get_chem();

					for (int j = 0; j < chem.size(); j++) {
						out << chem[j] << " ";
					}
					out << endl;

				}
				out.close();
			}
			break;
		}
			
		case 4:
		{
			o = 18;
			break;
		}
				
		}
		
	}
	
	return 0;
}