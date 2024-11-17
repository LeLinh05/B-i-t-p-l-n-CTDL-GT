#include<bits/stdc++.h>
using namespace std;

class Sinhvien{
	private:
		string ten;
		int tuoi;
		string masv;
		float diem;
	
	public:
		Sinhvien(const string& ten = "", int tuoi = 0, const string& masv ="", float diem = 0): ten(ten), tuoi(tuoi), masv(masv), diem(diem){}
		friend ostream& operator << (ostream& os, const Sinhvien& Sv){
			os << "Ten: " << Sv.ten << " ,tuoi: " << Sv.tuoi << " ,masv: " << Sv.masv << " ,diem: " << Sv.diem;
			return os;
		}
		
		friend istream& operator >> (istream& is, Sinhvien& Sv){
			cout << "Nhap ten sinh vien: ";
			is.ignore();
			getline(is, Sv.ten);
			cout << "Nhap tuoi sinh vien: ";
			is >> Sv.tuoi;
			is.ignore();
			cout << "Nhap ma sinh vien: ";
			getline(is, Sv.masv);
			cout << "Nhap diem: ";
			is >> Sv.diem;
			is.ignore();
			return is;
		}
		bool operator > (const Sinhvien& Sv) const{
			return this->diem > Sv.diem;
		}
		bool operator < (const Sinhvien& Sv) const{
			return this->diem < Sv.diem;
		}
		string getmasv() const {
			return masv;
		}		
		float getdiem() const {
			return diem;
		}
		string getten() const {
			return ten;
		}
		int gettuoi() const {
			return tuoi;
		}
		
		void setten(const string& ten) { 
			this->ten = ten;
			}
		void settuoi(int tuoi) { 
			this->tuoi = tuoi; 
		}
		void setmasv(const string& masv) {
			this->masv = masv; 
		}
		void setdiem(float diem) {
		 	this->diem = diem;
		}
};
template <class T>
class DsSinhvien{
	private:
		T ds; 
		
	public:
		DsSinhvien(){}
		~DsSinhvien(){}
		bool isempty(){
			return ds.empty();
		}
		void getsv(const Sinhvien& Sv){
			ds.push_back(Sv);
		}
		//in ra mh
		void print() const{
			for(auto it = ds.begin(); it != ds.end(); ++it){
				cout << *it << endl;
			}
		}
		//sap xep
		void sapxepgiam(){
			sort(ds.begin(), ds.end(), greater<Sinhvien>());
		}
		void sapxeptang(){
			sort(ds.begin(), ds.end());
		}
		//tim kiem
		Sinhvien maxdiem() const{
			Sinhvien max = ds[0];
			for(auto it = ds.begin(); it != ds.end(); ++it){
				if(it->getdiem() > max.getdiem()){
					max = *it;
				}
			}
			return max;
			
		}
		Sinhvien mindiem() const {
			Sinhvien min = ds[0];
			for(auto it = ds.begin(); it != ds.end(); ++it){
				if(it->getdiem() < min.getdiem()){
					min = *it;
				}
			}
			return min;
		}
		Sinhvien timsv(const string& masv){
			for(auto it = ds.begin(); it != ds.end(); ++it){
				if(it->getmasv() == masv){
					return *it;
				}
			}
			cout << "K tim thay sinh vien co ma: " << masv << endl;
		}
		//xoa sv dua tren ma sv
		void xoasv(const string& masv){
			for(auto it = ds.begin(); it != ds.end(); ++it){
				if(it->getmasv() == masv){
					it = ds.erase(it);
					cout << "Da xoa sv co ma: " << masv << endl;
					return;
				}
			}
			cout << "K tim thay sinh vien" << endl;	
		}
		void docfile(const string& name){
			ifstream infile(name);
			if(!infile){
				cout << "K mo duoc file!" << endl;
				return;
			}
			while(infile){
				Sinhvien Sv;
				string ten, masv;
				int tuoi;
				float diem;
				getline(infile, ten);
				if(infile.eof()){
					break;
				}
				infile >> tuoi;
				infile.ignore();
				getline(infile, masv);
				infile >> diem;
				infile.ignore();
				Sv.setten(ten);
				Sv.settuoi(tuoi);
				Sv.setmasv(masv);
				Sv.setdiem(diem);
				getsv(Sv);
			}
			infile.close();
			cout << "Da doc file\n";	
		}
};
class App{
	DsSinhvien<vector<Sinhvien>> dssv;
	public:
		App(){
			cout << "Khoi tao app" << endl;
		}
		~App(){
			cout << "Huy" << endl;
		}
		void menu(){
			int choice;
			do{
				cout << "1. Them sinh vien" << endl;
            	cout << "2. In ra danh sach Sinh vien" << endl;
            	cout << "3. Sap xep danh sach Sinh vien theo diem tang dan" << endl;
            	cout << "4. Sap xep danh sach Sinh vien theo diem giam dan" << endl;
            	cout << "5. Tim sinh vien co diem cao nhat" << endl;
            	cout << "6. Tim sinh vien co diem thap nhat" << endl;
            	cout << "7. Tim sinh vien theo ma Sinh vien" << endl;
            	cout << "8. Xoa sinh vien theo ma" << endl;
            	cout << "9. Nhap vao file sinh vien" << endl;
            	cout << "10. Thoat" << endl;
            	cout << "Lua chon: ";
            	cin >> choice;
            	
            	switch(choice){
            		case 1:{
            			Sinhvien Sv;
            			cin >> Sv;
            			dssv.getsv(Sv);
						break;
					}
					case 2:{
						dssv.print();
						break;
					}
					case 3:{
						cout << "Danh sach sau khi sap xep tang dan theo so diem la: " << endl;
						dssv.sapxeptang();
						dssv.print();
						break;
					}
					case 4:{
						cout << "Danh sach sau khi sap xep giam dan theo so diem la: " << endl;
						dssv.sapxepgiam();
						dssv.print();
						break;
					}
					case 5:{
						Sinhvien maxsv = dssv.maxdiem();
						cout << "Sinh vien co diem cao nhat la: " << maxsv << endl;
						break;
					}
					case 6:{
						Sinhvien minsv = dssv.mindiem();
						cout << "Sinh vien co diem thap nhat la: " << minsv << endl;
						break;
					}
					case 7:{
						string masv;
						cout << "Nhap ma sinh vien ma ban muon tim: ";
						cin >> masv;
						cout << "Sinh vien do la: " << dssv.timsv(masv) << endl;
						break;
					}
					case 8:{
						string masv;
						cout << "Nhap ma sinh vien ma ban muon xoa: ";
						cin >> masv;
						dssv.xoasv(masv);
						break;
					}
					case 9:{
						string name;
						cout << "Nhap ten file: ";
						cin >> name;
						dssv.docfile(name);
						break;
					}
					case 10:{
						cout << "Thoat chuong trinh" << endl;
						break;
					}
					default:
						cout << "Lua chon cua m k hop le!\n";
				}
			} while (choice != 10);
		}
};
main(){
	App app;
	app.menu();
}
