#include "lab5.h"

Student::Student(int _id, std::string _fio, int n_marks)
{
	id = _id;
	fio = _fio;

	for (auto i = 0; i < n_marks; i++)
	{
		this->marks.push_back(rand() % 5 + 1);
	}

}

void Student::enroll_to(Group *_group)
{
	this->group = _group;
}

void Student::add_mark(int  _mark)
{
	marks.push_back(_mark);
}

double Student::calc_progress()
{
	double avrg = 0;
	for (auto i = 0; i < marks.size(); i++)
	{
		avrg += marks[i];

	}
	return (avrg / marks.size());
}

Group::Group(std::string _title)
{
	title = _title;
};

void Group::enroll(Student &_student)
{
	_student.group = this;
	students.push_back(&_student);
	cout << (&_student)->fio << " has been enrolled in " << this->title << endl;

}
Student * Group::search(string _fio)
{
	for (auto i = 0; i < students.size(); i++)
	{
		if (this->students[i]->fio == _fio)
		{
			return students[i];
		}
	}
	std::cout << "There is no " << _fio << " in " << this->title << " !" << std::endl;
	return NULL;
}
Student * Group::election()
{
	if (students.size() > 1)
	{
		int new_head = rand() % students.size();
		this->head = students[new_head];
		cout << this->head->fio << " is a new head of " << this->title << endl;
		return this->head;
	}
	else
	{
		return NULL;
	}

}
bool Group::removal(Student *_student)
{
	if (_student->group == this)
	{
		for (auto i = 0; i < this->students.size(); i++)
		{
			if (students[i]->id == _student->id)
			{
				std::cout << _student->fio << " is dissmised! " << std::endl;
				students.erase(students.begin() + i);
				if (_student == this->head)
				{
					this->election();
					std::cout << "A new head of " << this->title << " is " << this->head->fio << std::endl;
				}
				return true;
			}
		}
	}
	else
	{
		std::cout << "There is no" << _student->fio << " in " << this->title << " !" << std::endl;
		return false;
	}

}
double Group::calc_avrg()
{
	double avrg = 0;
	for (auto i = 0; i < students.size(); i++)
	{
		avrg += (*students[i]).calc_progress();

	}
	return (avrg / students.size());
}

Deanery::Deanery(string _file)
{
	srand(time(0));
	ifstream file(_file);
	if (!file)
	{
		cout << "Error in opening file for reading !" << endl;
		return;
	}
	string buf;
	int pos, id = 0, n_marks = 5;
	Group  *_group = NULL;
	while (getline(file, buf))
	{
		if (buf.find("END") != buf.npos)
		{
			for (auto i = 0; i < groups.size(); i++)
			{
				groups[i]->election();
				cout << "The election of the head in a group #" << i + 1 << endl;
			}
			cout << "END OF PROCCESS!" << endl;;
			return;
		}
		if (buf.find("group") != buf.npos)
		{
			cout << "group making" << endl;
			pos = buf.find("group");
			_group = new Group(buf.substr(0, pos - 1));
			groups.push_back(_group);
		}
		else
		{
			Student *_student = new Student(id, buf, n_marks);
			(*_group).enroll(*_student);
			this->students.push_back(_student);
			id++;
		}
	}
	return;
}
Group * Deanery::searchGroup(string title)
{
	for (auto i = 0; i < groups.size(); i++)
	{
		if (groups[i]->title == title)
		{
			return groups[i];
		}
	}
	return NULL;
}
bool Deanery::transfer(string fio, Group *group)
{
	Student * st = NULL;
	for (auto i = 0; i < groups.size(); i++)
	{

		st = (*groups[i]).search(fio);
		if (st != NULL)
		{
			break;
		}
	}
	if (st == NULL)
	{
		cout << "There is no " << fio << " in the Deanery" << endl;
		return false;
	}
	if (st->group == group)
	{
		cout << fio << "is already in" << st->group->title << endl;
		return false;
	}
	else
	{
		cout << fio << " is transfered  from " << st->group->title << " to " << group->title << endl;
		st->group->removal(st);
		group->enroll(*st);
		if (st == st->group->head)
		{
			st->group->election();
		}
		return true;
	}

}
void Deanery::checkProgress(double limit)
{
	cout << endl << "THE LIST OF UDNDERACHIEVERS: (GPA below " << limit << ")" << endl << endl;
	for (auto i = 0; i < groups.size(); i++)
	{
		cout << groups[i]->title << ":" << endl;
		int total = 0, counter = 0, N;
		N = groups[i]->students.size();
		for (auto j = N - 1; j >= 0; j--)
		{
			counter++;
			if ((groups[i]->students[j]->calc_progress()) <= limit)
			{
				this->groups[i]->removal(groups[i]->students[j]);
				total++;
			}
		}
		cout << "Total: " << total << endl;
	}
	cout << endl << "THE END OF THE LIST. " << endl << endl;
	return;
}
void Deanery::reelection()
{
	for (auto i = 0; i < groups.size(); i++)
	{
		groups[i]->election();
	}
}
void Deanery::updateData(string _file)
{
	ofstream fout(_file);
	for (auto i = 0; i < groups.size(); i++)
	{
		fout << this->groups[i]->title << " group" << endl;
		for (auto j = 0; j < groups[i]->students.size(); j++)
		{
			fout << this->groups[i]->students[j]->fio << endl;
		}
	}
	fout << "END";
	fout.close();
}
void Deanery::printStatics()
{
	for (auto i = 0; i < this->groups.size(); i++)
	{
		cout << endl << "Group: " << groups[i]->title << " has " << groups[i]->students.size() << " students. The avrg progress is  " << groups[i]->calc_avrg() << endl;
		cout << endl << "The head of " << groups[i]->title << " is " << groups[i]->head->fio << "  with ID: " << groups[i]->head->id << endl << endl;
		for (auto j = 0; j < (this->groups[i]->students.size()); j++)
		{
			cout << "ID: " << this->groups[i]->students[j]->id << " avrg_mark: " << this->groups[i]->students[j]->calc_progress() << "   " << groups[i]->students[j]->fio;
			for (auto k = 0; k < (this->groups[i]->students[j]->marks.size()); k++)
			{
				cout << " " << this->groups[i]->students[j]->marks[k];
			}
			cout << endl;

		}

	}
}