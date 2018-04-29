//**********************************************************************************************************************************************************//
//	Plik: C_menu.cpp																										Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu.hpp"

C_menu::C_menu() {
	//	Tab_menu = new Menu_base*[i_value];
};
void C_menu::m_loader(std::vector<std::vector<std::string>>& v_s, std::vector<bool>& v_b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<std::vector<int>>>& V_procedur, std::vector<int>& V_iterator, std::vector<int>& V_typ_menu) {
	Tab_menu = new C_menu_base*[v_s.size()];
	i_size = v_s.size(); // przepisanie rozmiaru vectora
	std::vector<bool>::iterator it = v_b.begin(); //stworzenie iteratora od vectora boola
	std::vector<std::vector<int>>::iterator it_i = v_k.begin(); //stworzenie iteratora do vector�w typu int
	std::vector<std::vector<std::vector<int>>>::iterator it_proc = V_procedur.begin();
	std::vector<std::list<C_person_base*>> V_L_person;
	std::vector<int>::iterator it_start = V_iterator.begin();
	std::vector<int>::iterator it_typ_menu = V_typ_menu.begin();
	std::vector<std::vector<std::string>> V_temp;
	std::vector<std::vector<int>> V_temp_i;
	int i; //int iterator fora
	for (i = 0; i < v_s.size(); i++) {
		V_temp.push_back(v_s[i]);
		V_temp_i.push_back(*it_i);
		//V_L_person.push_back(L_peron);
		Tab_menu[i] = f.m_Create_menu(*it_typ_menu, *it, V_temp, V_temp_i,*it_proc, *it_start, V_L_person);
		V_temp.clear();
		V_temp_i.clear();
		it_start++;
		it_typ_menu++;
		it_proc++;
		it_i++;
		it++;
	}
}
void C_menu::m_view(int& i_variable, int& i_klucz,std::vector<int>& V_proces, int& i_choice) {
		if (i_variable >= 0 && i_variable < i_size) {
			Tab_menu[i_variable]->m_view(i_variable, i_klucz, V_proces, i_choice); //do rozwoju trza zaprojektowac lejalt menu
		}
}
void C_menu::m_view(int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) {
	if (i_variable >= 0 && i_variable < i_size) {
		Tab_menu[i_variable]->m_view(i_variable,s_result, i_klucz, V_proces, i_choice); //do rozwoju trza zaprojektowac lejalt menu
	}
}
void C_menu::m_set_content(std::list<C_person_base*>& Lista) {
	std::list<C_person_base*> lista;
	lista = Lista;
	std::string s_data;
	std::vector<std::string> V_content;
	int i_iter;
	for (auto& X : lista) {
		s_data.clear();
		X->m_conwert(s_data);
		V_content.push_back(s_data);
	}
	for (i_iter = 0; i_iter < i_size; i_iter++) {
		Tab_menu[i_iter]->m_set_str(V_content);
	}
	V_str.clear();
}
C_menu::~C_menu() {
	delete[]Tab_menu;
}
void C_menu::m_set_content_person(int i_choice,std::vector<std::list<C_person_base*>>& lista) {
	Tab_menu[i_choice]->m_add_perosons(lista);
}
void C_menu::m_set_str(int i_varaible,std::vector<std::vector<std::vector<std::string>>>& v_str) {
	if (i_varaible >= 0 && i_varaible < i_size) {
		Tab_menu[i_varaible]->m_set_content(v_str);
	}
}
void C_menu::m_get_str(int i_variable,std::vector<std::vector<std::vector<std::string>>>& v_str) {
	if (i_variable >= 0 && i_variable<i_size)
		Tab_menu[i_variable]->m_get_content(v_str);
}