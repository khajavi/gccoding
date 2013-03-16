/*
 * Adopted from http://cplusplusbench.blogspot.com/2007/05/mvc-simple-implementation.html
 */

#include <iostream>
#include <vector>
using namespace std;

class Observer {
	public:
		virtual void update() = 0;
};

class Subject {
	public:
		virtual void subscribe(Observer*) = 0;
		virtual void unsubscribe() = 0;
};

class EmployeeModel : public Subject {
	vector<Observer*> observer_map_;
	int age_;

	void notify_observers() {
		for( int i = 0; i < observer_map_.size(); i++ ) {
			observer_map_[i]->update();
		}
	}

public:
	void subscribe(Observer* observing_object) {
		observer_map_.push_back(observing_object);
	}	

	void unsubscribe() {

	}

	int get_age() {
		return age_;
	}

	void set_age(int age) {
		age_= age;
		notify_observers();
	}
};

class Controller {
	Subject* subject_;
public:
	Controller(Subject* subject) {
		subject_ = subject;
	}

	void modify_age(int new_age) {
		(dynamic_cast<EmployeeModel*>(subject_))->set_age(new_age);
	}

	void subscribe(Observer* view_object) {
		subject_->subscribe(view_object);
	}

};


class View : public Observer {
private:
	Controller* controller_;
public:
	View(Controller* controller) {
		controller_ = controller;
		controller_->subscribe(this);
	}

	void enter_age() {
		cout << "Enter Age" ;
		int x = 0;
		cin >> x;
		controller_->modify_age(x);
	}

	void update() {
		cout << "view updater called ... ";
	}
};



int main (int argc, char const* argv[]) {
	EmployeeModel* model = new EmployeeModel();
	Controller* controller = new Controller(model);
	View* view = new View(controller);

	view->enter_age();

	return 0;
}








