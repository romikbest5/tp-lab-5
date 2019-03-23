#include "lab5.h"


Student::Student(int id_, string fio_) {
	id = id_;
	fio = fio_;
}

void Student::add_group(Group * group) {
	this->group = group;

}

void Student::add_mark(int _mark) {
	marks.push_back(_mark);
	num = marks.size();
}

double Student::student_average() {
	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += marks[i];
	}
	return (sum / num);
}


Group::Group(string title_) {
	title = title_;
};

void Group::add_student(Student *student) {
	students.push_back(student);
	num = students.size();
}

Student * Group::elect_head() {
	if (students.size() > 0) {
		if (num > 1) {
			int _head = rand() % num;
			head = students[_head];
			return head;
		}
		else head = students[0];
		return head;
	}
	else return nullptr;
}

Student * Group::search_student(int id_) {
	for (int i = 0; i < num; i++) {
		if (students[i]->id == id_) {
			return students[i];
		}
	}
}

double Group::group_average() {
	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += students[i]->student_average();
	}
	return (sum / num);
}

void Group::exception(string title_) {
	for (int i = 0; i < num; i++) {
		if (students[i]->fio == title_) {
			if (students[i] == head) {
				students.erase(students.begin() + i);
				num--;
				elect_head();
			}
			else {
				students.erase(students.begin() + i);
				num--;
			}
		}
	}
}


Deanery::Deanery(string title_students, string title_groups) {
	fileStudents = title_students;
	fileGroups = title_groups;
}

void Deanery::create_students() {
	ifstream file(fileStudents);
	string fio_student;
	int id_ = 100;
	while (getline(file, fio_student)) {
		id_++;
		students.push_back(new Student(id_, fio_student));
	}
	file.close();

	num_st = students.size();
}

void Deanery::create_groups() {
	ifstream file(fileGroups);
	string title_groups;
	while (getline(file, title_groups)) {
		groups.push_back(new Group(title_groups));
	}
	file.close();

	num_gr = groups.size();

	int num_in_gr = num_st / num_gr;
	for (int i = 0; i < num_gr; i++) {
		for (int j = i * num_in_gr; j < (i + 1)*num_in_gr; j++) {
			students[j]->add_group(groups[i]);
			groups[i]->add_student(students[j]);
		}
	}
}
void Deanery::add_marks() {
	int mark;
	for (int i = 0; i < num_st; i++) {
		for (int n = 0; n < 5; n++) {
			mark = rand() % 5 + 1;
			students[i]->add_mark(mark);
		}
	}
}

void Deanery::change_group(string title_student, string title_new_group) {
	for (int i = 0; i < num_st; i++) {
		if (students[i]->fio == title_student) {
			for (int k = 0; k < num_gr; k++) {
				if (groups[k]->title == title_new_group) {
					Group * last_gr = students[i]->group;
					students[i]->add_group(groups[k]);
					groups[k]->add_student(students[i]);
					last_gr->exception(students[i]->fio);
				}
			}

		}
	}
}

void Deanery::exception_student() {
	for (int i = 0; i < num_st; i++) {
		if (students[i]->student_average() < 2) {
			students[i]->group->exception(students[i]->fio);
			students.erase(students.begin() + i);
			num_st--;
			i--;
		}
	}
}

void Deanery::elect_ghead() {
	for (int i = 0; i < num_gr; i++) {
		groups[i]->elect_head();
	}
}

void Deanery::get_statistics(string title_) {

	for (int i = 0; i < num_st; i++) {
		student_stat.push_back(pair<float, string>(students[i]->student_average(), students[i]->fio));
	}sort(student_stat.begin(), student_stat.end());

	for (int j = 0; j < num_gr; j++) {
		group_stat.push_back(pair<float, string>(groups[j]->group_average(), groups[j]->title));
	}sort(group_stat.begin(), group_stat.end());

	ofstream file;
	file.open(title_);
	if (file.is_open())
	{
		for (int j = 0; j < student_stat.size(); j++) {
			file << student_stat[j].second << "-" << student_stat[j].first << endl;
		}
		for (int i = 0; i < group_stat.size(); i++) {
			file << group_stat[i].second << "  -  " << group_stat[i].first << endl;
		}
	}file.close();
}

void Deanery::update(string title_) {
	ofstream file;
	file.open(title_);

	if (file.is_open())
	{
		file << "The number of students is  " << num_st << endl;
		for (int i = 0; i < num_gr; i++) {
			file << "In " << groups[i]->title << " " << groups[i]->num << " people. " << " The averade groups mark - " << groups[i]->group_average() << endl;
			file << "Head: " << groups[i]->head->fio << endl;
			for (int j = 0; j < groups[i]->students.size(); j++) {
				file << groups[i]->students[j]->fio << "-" << groups[i]->students[j]->student_average() << "   ";
				for (int h = 0; h < groups[i]->students[j]->marks.size(); h++) {
					file << groups[i]->students[j]->marks[h] << " ";
				}
				file << endl;
			}
			file << endl;
		}
	}file.close();
}

void Deanery::print_info() {
	cout << "Number students is  " << num_st << endl;

	for (int i = 0; i < num_gr; i++) {
		cout << "In " << groups[i]->title << " " << groups[i]->num << " people. " << " The averade groups mark? " << groups[i]->group_average() << endl;
		cout << "Head: " << groups[i]->head->fio << endl;
		for (int j = 0; j < groups[i]->students.size(); j++) {
			cout << groups[i]->students[j]->fio << "-" << groups[i]->students[j]->student_average() << "    ";
			for (int h = 0; h < groups[i]->students[j]->marks.size(); h++) {
				cout << groups[i]->students[j]->marks[h] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << endl << "Statistics" << endl;
	for (int j = 0; j < student_stat.size(); j++) {
		cout << student_stat[j].second << "-" << student_stat[j].first << endl;
	}

	for (int i = 0; i < group_stat.size(); i++) {
		cout << group_stat[i].second << "  -  " << group_stat[i].first << endl;
	}
}