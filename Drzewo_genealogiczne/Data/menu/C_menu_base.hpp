//**********************************************************************************************************************************************************//
//	Plik: C_menu_base.hpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Rozbudowa metody wirtualnej m_view(), o dodatkowy argument int& i_klucz											//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_BASE_HPP
#define C_MENU_BASE_HPP
#include <vector>
#include <string>
#include <list>
#include "../person/C_fabric_person.hpp"
#include <windows.h>
class C_menu_base {
protected:
	std::vector<std::vector<std::vector<std::string>>> V_str;
	std::vector<std::list<C_person_base*>> V_L_person; //lista personow
	std::vector<std::vector<int>> V_klucz; //listaklucyz
	std::vector<std::vector<int>> V_procedur;
	int i_start;
	bool b_dinamic;
public:
	C_menu_base( std::vector<std::vector<std::string>>& v, bool b_value,  std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person); //konstruktor parametrowy
	virtual void m_view(int& i_variable,int& i_klucz, std::vector<int>& V_proces, int& i_choice) = 0; //metoda powodujaca ze klasa C_menu_base jest klasa abstrakcyjna
	virtual void m_view(int& i_variable,std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) = 0; //metoda powodujaca ze klasa C_menu_base jest klasa abstrakcyjna
	void m_load( std::vector<std::vector<std::vector<std::string>>> v); //metoda lafujaca danych
	void m_ruch(void(*f)(int& x, std::string& i_klucz, int& i_start, std::vector<std::string>& v_k), int& i_klawisz, std::string& i_klucz, int& i_start, std::vector<std::string>& v_k);
	void m_ruch(void(*f)(int& x, int& i_klucz, int& i_start, std::vector<int>& v_k), int& i_klawisz, int& i_klucz, int& i_start, std::vector<int>& v_k); //metoda umozliwiajaca ruch w menu
	void m_ruch(void(*f)(int& x, std::string& i_klucz, std::string& s_message, int& i_start, std::vector<std::string>& v_k), int& i_klawisz, std::string& i_klucz, std::string& s_message, int& i_start, std::vector<std::string>& v_k);
	void m_get_content( std::vector<std::vector<std::vector<std::string>>>& V_CONTENT); //metoda do wyciagania vektor typu string
	void m_set_content( std::vector<std::vector<std::vector<std::string>>>& V_CONTENT); //metoda do dodawania vektor typu string
	void m_set_str(std::vector<std::string>& v_str);
	void m_get_str(int i_choice, std::vector<std::string>& v_str);
	void m_add_perosons(std::vector<std::list<C_person_base*>>& L_person);
	virtual ~C_menu_base(); //destruktor
};
void f_sterowanie(int& x, int& i_klucz,int& i_start, std::vector<int>& v_k);
void f_sterowanie(int& x, std::string& s_klucz, int& i_start, std::vector<std::string>& v_k);
void f_option_clear(HANDLE& h, COORD& pos, DWORD& Written);
void f_clear(HANDLE& h, COORD& pos, DWORD& Written);
static char C_massage[2];
#endif // !C_MENU_BASE_HPP