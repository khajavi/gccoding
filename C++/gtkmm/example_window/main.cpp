#include <iostream>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/radiobutton.h>

using namespace Gtk;

void on_button_clicked();
void on_radio_button1_clicked();

int main(int argc, char* argv[]) {
	
	Main kit(argc, argv);
	
	Window window;
	window.set_title("Hello");
	window.set_border_width(16);
	Button m_button("Hello");

	Box m_box_top(ORIENTATION_VERTICAL);
	Box m_box1(ORIENTATION_VERTICAL, 10);
	Box m_box2(ORIENTATION_VERTICAL, 10);

	window.add(m_box_top);

	RadioButton m_radiobutton1("button1");
	RadioButton m_radiobutton2("button2");
	RadioButton m_radiobutton3("button3");
	
	Button m_button_close("close");

	RadioButton::Group group = m_radiobutton1.get_group();
	m_radiobutton2.set_group(group);
	m_radiobutton3.set_group(group);


	m_box_top.pack_start(m_box1);
	m_box_top.pack_start(m_box2);

	m_box1.set_border_width(10);
	m_box2.set_border_width(10);
	
	m_box1.pack_start(m_radiobutton1);
	m_box1.pack_start(m_radiobutton2);
	m_box1.pack_start(m_radiobutton3);

	m_box2.pack_start(m_button_close);

	m_button_close.set_can_default();
	m_button_close.grab_default();

	m_radiobutton2.set_active();


	m_button_close.signal_clicked()
		.connect(sigc::ptr_fun(&on_button_clicked));
	m_radiobutton1.signal_clicked()
		.connect(sigc::ptr_fun(&on_radio_button1_clicked));


	
//	window.add(m_button);
	window.show_all_children();
	Main::run(window);

	return 0;
}

void on_radio_button1_clicked() {
	std::cout << "radio button 1 clicked" << std::endl;
}


void	on_button_clicked() {
	std::cout << "hide" << std::endl;
}
