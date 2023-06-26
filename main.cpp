#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

class SoTietKiem {
    public:
		string hoTen;
	    string maKhachHang;
	    string soChungMinhThu;
	    float soTienGui;
	    string ngayLapSo;
	    float laiSuat;
	    int kyHan;
};

const int maxrow = 10;

string makhachhang[maxrow] = {};
string ten[maxrow] = {};
string socmt[maxrow] = {};
string tiengui[maxrow] = {};
string ngaylapso[maxrow] = {};
string laisuat[maxrow] = {};
string kyhan[maxrow] = {};


class NganHang{
private:
    string tenNganHang;
    string diaChi;
    string maSoThue;
    string dienThoai;
    string email;
    vector<SoTietKiem> dsSoTietKiem;

public:
    NganHang(string ten, string diaChi, string maSoThue, string dienThoai, string email){
        this->tenNganHang = ten;
        this->diaChi = diaChi;
        this->maSoThue = maSoThue;
        this->dienThoai = dienThoai;
        this->email = email;
    }
	
	
	void nhapSoTietKiem(){
		SoTietKiem stk;
        cout << "Nhap thong tin so tiet kiem:" << endl;
		cin.ignore();
		cout << "Ho ten khach hang: ";
		getline(cin, stk.hoTen);
		cout << "Ma khach hang: ";
		getline(cin, stk.maKhachHang);
		cout << "So chung minh thu: ";
        getline(cin, stk.soChungMinhThu);
		cout << "So tien gui (trieu dong): ";
        cin >> stk.soTienGui;
        char stg[10];
		sprintf(stg,"%f",stk.soTienGui);
		cout << "Ngay lap so (dd/mm/yyyy): ";
        cin.ignore();
        getline(cin, stk.ngayLapSo);
		cout << "Lai suat: ";
        cin >> stk.laiSuat;
        char lai[10];
		sprintf(lai,"%f",stk.laiSuat);
        cout << "Ky han (thang), nhap 0 neu khong co: ";
        cin >> stk.kyHan;
        char kh[10];
		sprintf(kh,"%d",stk.kyHan);
		
		for(int i = 0;i < maxrow;i++){
        	if(makhachhang[i] == "\0"){
        		makhachhang[i] = stk.maKhachHang;
				ten[i] = stk.hoTen;
				socmt[i] = stk.soChungMinhThu;
				tiengui[i] = stg;
				ngaylapso[i] = stk.ngayLapSo;
				laisuat[i] = lai;
				kyhan[i] = kh;	
			
				break;			
			}
		}
		
		dsSoTietKiem.push_back(stk);
        cout << "Them so tiet kiem thanh cong!" << endl;
        
        
	}

    void tinhLaiSuat(int index) {
        SoTietKiem stk = dsSoTietKiem[index];
        float tienLai = 0.0;
        time_t now = time(0);
        tm* currentTime = localtime(&now);
        int soThangGui = (currentTime->tm_year + 1900) * 12 + currentTime->tm_mon - (stoi(stk.ngayLapSo.substr(6, 4)) * 12 + stoi(stk.ngayLapSo.substr(3, 2)));

        if (stk.kyHan == 0) {
            tienLai = stk.soTienGui * stk.laiSuat * soThangGui;
        } else {
            if (soThangGui >= stk.kyHan) {
                tienLai = stk.soTienGui * stk.laiSuat * stk.kyHan;
            }
        }

        cout << "Tien lai cua so tiet kiem " << stk.maKhachHang << " la: " << tienLai << " trieu dong." << endl;
    }

    void tinhTongLaiSuat() {
        float tongLaiSuat = 0.0;
        time_t now = time(0);
        tm* currentTime = localtime(&now);
        int currentYear = currentTime->tm_year + 1900;
        int currentMonth = currentTime->tm_mon;

        for (const SoTietKiem& stk : dsSoTietKiem) {
            int soThangGui = currentYear * 12 + currentMonth - (stoi(stk.ngayLapSo.substr(6, 4)) * 12 + stoi(stk.ngayLapSo.substr(3, 2)));

            if (stk.kyHan == 0) {
                tongLaiSuat += stk.soTienGui * stk.laiSuat * soThangGui;
            } else {
                if (soThangGui >= stk.kyHan) {
                    tongLaiSuat += stk.soTienGui * stk.laiSuat * stk.kyHan;
                }
            }
        }

        cout << "Tong tien lai cua ngan hang la: " << tongLaiSuat << " trieu dong." << endl;
    }

    
	
	void timsotietkiem(){
		
	}
	
	void xuatDanhSachSoTietKiem() {
        cout << "Danh sach cac so tiet kiem: " << endl;
        ifstream output;
		output.open("D:\\DanhsachSoTietKiem.txt");
		if(!output.is_open()){
			cout << "Khong the mo file ! \n";
		}
        
		vector<string> lines;
        string line;
        while(getline(output,line)){
        	lines.push_back(line);
		}
		
		for(const auto &i : lines)
        	cout << i << endl;	
    }
};

void ghiFile(int i){

		ofstream input("D:\\DanhsachSoTietKiem.txt", ios::app);
		    	if(input.is_open() == NULL){
		    		cout << "Khong mo duoc file !";
				}
				if(makhachhang[i] != "\0"){
						input << setw(3) << right << i+1 ; 
						input << setw(15)  << right << makhachhang[i]; 
						input << setw(20) << right << ten[i]; 
						input << setw(18) << right << socmt[i]; 
						input << setw(15) << right << tiengui[i]; 
						input << setw(15) << right << ngaylapso[i];
						input << setw(11) << right << laisuat[i] ;
						input << setw(5) << right << kyhan[i] << endl;
						i++;
				} 
				
				input << "  ==================================================================================================  " << endl;
	}

class Quanlistk{
	public:
	    void insertPlayerformfile();
	    void find_player_by_name(string name);
	    void showallplayer();
	    void find_team_by_name(string name);
	    void find_team_by_id(string id);
	    void insert_team_from_file();
	    void insert_Match_from_file();
	    void show_all_team();
	    void show_all_match();
	    void find_match_by_date(string date);
	    void find_match_by_stadium(string st);
	    void find_match_by_team(string team);
	    void find_team_by_coach(string coach);
	    void find_team_by_location(string location);
	    string get_idteam_by_nameTeam(string name);
	    void removePlayerbyName(string name);
	    void removeTeambyname(string name);
	    void removeMatchbyindex(int n);
	    void Playerxuatcsv();
	    void Teamxuatcsv();
	    void Matchxuatcsv();
	};   
	    
	void FootballManager::Matchxuatcsv(){
	    ofstream csv("info/Match.csv");
	    csv<<"Ngay thi dau;San thi dau;Ten doi bong 1;Ten doi bong 2;Ti so\n";
	    insert_Match_from_file();
	    csv.close();
	    for (Match &match : list_match){
	        match.show_inf();
	        match.savefilecsv();
	    }
	}
	
	
	void FootballManager::Playerxuatcsv(){
	    ofstream csv("info/player.csv");
	    csv<<"Ho Ten;cmnd;Quoc Tich;Ngay sinh;Chieu cao;Can Nang;Vi tri choi;Id Team\n";
	    insertPlayerformfile();
	    csv.close();
	    for (Player &player : list_player){
	        player.show_inf();
	        player.savefilecsv();
	    }
	}
	
	void FootballManager::Teamxuatcsv(){
	    ofstream csv("info/team.csv");
	    csv<<"ID Team;Ten doi bong;Dia phuong;Huan luyen vien\n";
	    insert_team_from_file();
	    csv.close();
	    for (Team &team : list_team){
	        team.show_inf();
	        team.savefilecsv();
	    }
	}
	
	void clearFile(string typee){
	    string path = "info/"+typee;
	    ofstream MyFile(path, std::ios::out | std::ios::trunc);
	    MyFile<<"";
	    MyFile.close();
	    
	}   
	
	void FootballManager::removeMatchbyindex(int n){
	        list_match.erase(list_match.begin()+n);
	        clearFile("Match.txt");
	        for(Match &match : list_match){
	            match.insert_to_file();
	            cout<<"Đã xóa \n";
	            }
	}
	
	void FootballManager::removeTeambyname(string name){
	    Team target;
	    for (Team &team : list_team){
	        if (team.get_name()==name)
	        {
	            target = team;
	            target.show_inf();
	        }
	    }
	    auto it = find(list_team.begin(), list_team.end(), target);
	    if (it != list_team.end()) {
	        // Tìm thấy phần tử
	        int index = distance(list_team.begin(), it);
	        cout<<index;
	        list_team.erase(list_team.begin() + index);
	        clearFile("Team.txt");
	        for(Team &team : list_team){
	        team.insert_team_to_file();
	        cout<<"Đã xóa \n";
	        }
	    }
	    else {
	        cout<<"Không tồn tại\n";
	    }
	}
	void FootballManager::removePlayerbyName(string name){
	    Player target;
	    for (Player &player : list_player){
	        if (player.get_name()==name)
	        {
	            target = player;
	            target.show_inf();
	        }
	    }
	    auto it = find(list_player.begin(), list_player.end(), target);
	    if (it != list_player.end()) {
	        // Tìm thấy phần tử
	        int index = distance(list_player.begin(), it);
	        cout<<index;
	        list_player.erase(list_player.begin() + index);
	        clearFile("player.txt");
	        for(Player &player : list_player){
	        player.insert_player_to_file();
	        }
	        cout<<"Đã xóa \n";
	
	    } else {
	        cout<<"Không tồn tại\n";
	    }
	}
	
	void FootballManager::find_match_by_team(string team){
	    for(Match &macth : list_match){
	        if (macth.get_team1()==team)
	        {
	            macth.show_inf();
	        }
	        
	    }
	    for(Match &macth : list_match){
	        if (macth.get_team2()==team)
	        {
	            macth.show_inf();
	        }
	        
	    }
	}
	
	void FootballManager::find_match_by_stadium(string st){
	    for(Match &macth : list_match){
	        if (macth.get_stadium()==st)
	        {
	            macth.show_inf();
	        }
	        
	    }
	}
	void FootballManager::find_match_by_date(string date){
	    for(Match &macth : list_match){
	        if (macth.get_date()==date)
	        {
	            macth.show_inf();
	        }
	        
	    }      
	}
	void FootballManager::show_all_match(){
	    for (Match &match : list_match){
	        match.show_inf();
	        cout << "\n====================================="<<endl;
	    }
	}
	
	void FootballManager::insert_Match_from_file(){
	    ifstream read_player("info/Match.txt"); // mở file để đọc
	    string input;                            // đọc từng dòng rồi cho vào input
	    vector<string> all_lines;                // 1 mảng gồm nhiều input   
	    while (getline(read_player, input))
	    {
	        all_lines.push_back(input); // thêm input vào mảng
	    }
	    
	    string item;
	    for (const string &line : all_lines)
	    {
	        vector<string> elements;        
	        stringstream ss(line);
	        while (getline(ss, item, ';'))
	        {
	            elements.push_back(item);
	        }
	        Match match(elements[0], elements[1], elements[2], elements[3],stoi(elements[4]),stoi(elements[5]));
	        list_match.push_back(match);
	    }
	}
	
	string FootballManager::get_idteam_by_nameTeam(string name){
	    for(Team &team : list_team){
	        if (team.get_name()==name)
	        {
	            return team.get_id();
	        }
	        
	    }
	
	}
	
	
	void FootballManager::find_team_by_location(string location){
	    for(Team &team : list_team){
	        if (team.get_location()==location)
	        {
	            team.show_inf();
	                cout << "=============================================================\n";
	
	        }
	        
	    }       
	}
	
	void FootballManager::find_team_by_coach(string coach){
	    for(Team &team : list_team){
	        if (team.get_coach()==coach)
	        {
	            team.show_inf();
	            cout << "=============================================================\n";
	
	        }
	        
	    }       
	}
	
	void FootballManager::find_team_by_id(string id){
	    for(Team &team : list_team){
	        if (team.get_id()==id)
	        {
	            team.show_inf();
	            cout << "=============================================================\n";
	
	        }
	        
	    }        
	}
	
	void FootballManager::find_team_by_name(string name){
	    for(Team &team : list_team){
	        if (team.get_name()==name)
	        {
	            team.show_inf();
	            cout << "=============================================================\n";
	
	        }
	        
	    }        
	}
	
	void FootballManager::insert_team_from_file(){
	    ifstream read_player("info/Team.txt"); // mở file để đọc
	    string input;                            // đọc từng dòng rồi cho vào input
	    vector<string> all_lines;                // 1 mảng gồm nhiều input   
	    while (getline(read_player, input))
	    {
	        all_lines.push_back(input); // thêm input vào mảng
	    }
	    
	    string item;
	    for (const string &line : all_lines)
	    {
	        vector<string> elements;        
	        stringstream ss(line);
	        while (getline(ss, item, ';'))
	        {
	            elements.push_back(item);
	        }
	        Team team(elements[0], elements[1], elements[2], elements[3]);
	        list_team.push_back(team);
	    }
	}
	void FootballManager::show_all_team(){
	    for (Team &team : list_team){
	        team.show_inf();
	        cout << "=============================================================\n";
	
	    }
	}
	void FootballManager::insertPlayerformfile(){
	    ifstream read_player("info/player.txt"); // mở file để đọc
	    string input;                            // đọc từng dòng rồi cho vào input
	    vector<string> all_lines;                // 1 mảng gồm nhiều input   
	    while (getline(read_player, input))
	    {
	        all_lines.push_back(input); // thêm input vào mảng
	    }
	    
	    string item;
	    for (const string &line : all_lines)
	    {
	        vector<string> elements;        
	        stringstream ss(line);
	        while (getline(ss, item, ';'))
	        {
	            elements.push_back(item);
	        }
	        Player player(elements[0], elements[1], elements[2], elements[3], elements[4], elements[5], elements[6],elements[7]);
	        list_player.push_back(player);
	    }
	}
	
	void FootballManager::showallplayer(){
	    for (Player &player :list_player){
	        player.show_inf();
	        cout << "============================================================================================" << endl;
	    }
	}
	
	void FootballManager::find_player_by_name(string name){
	    for (Player &player : list_player){
	        if (player.get_name()==name)
	        {
	            player.show_inf();
	            cout << "============================================================================================" << endl;
	        }
	    }
	}
	
	void TeamTitle(){
	    cout << "=============================================================\n";
	    cout << setw(8) << "Id" << setw(24) << "Tên đội bóng" << setw(20) << "Địa phương" << setw(24) << "Huấn luyện viên" << endl;
	    cout << "=============================================================\n";
	}
	void Menustk(){
	    int chon;
	
	    do
	    {
	        system("cls");
	        cout<<"====================  MENU  ========================\n";
	        cout<<"|| 1.Hiển thị danh sách sổ tiết kiệm\n";
	        cout<<"|| 2.Tìm kiếm sổ tiết kiệm theo tên khách hàng \n";
	        cout<<"|| 3.Tìm kiếm sổ tiết kiệm theo mã khách hàng \n";
	        cout<<"|| 4.Thêm sổ tiết kiệm \n";
	        cout<<"|| 5.Hiển thị danh sách sổ tiết kiệm có kỳ hạn\n";
	        cout<<"|| 6.Hiển thị danh sách sổ tiết kiệm không có kỳ hạn\n";
	        cout<<"|| 7.Xóa đội bóng theo tên \n";      
	        cout<<"|| 0.Quay lại menu chính\n";
	        cout<<"====================  END  =======================\n";
	        cout<<"Nhap lua chon : ";
	        fflush(stdin);
	        cin>>chon;
	        if (chon == 1){
	            FootballManager fmng;
	            TeamTitle();
	            fmng.insert_team_from_file();
	            fmng.show_all_team();
	            system("pause");
	        }
	        else if (chon==2)
	        {
	            FootballManager fmng;
	            string name;
	            cout<<"Nhập tên đội bóng cần tìm kiếm : ";
	            fflush(stdin);
	            getline(cin,name);
	            TeamTitle();
	            fmng.insert_team_from_file();
	            fmng.find_team_by_name(name);
	            system("pause");
	
	        }
	        else if (chon==3)
	        {
	            FootballManager fmng;
	            string id;
	            cout<<"Nhập id đội bóng cần tìm kiếm : ";
	            fflush(stdin);
	            getline(cin,id);
	            TeamTitle();
	            fmng.insert_team_from_file();
	            fmng.find_team_by_id(id);
	            system("pause");
	
	        }
	        else if (chon == 4)
	        {
	            string coach;
	            cout<<"Nhập tên huấn luyện viên :";
	            fflush(stdin);
	            getline(cin,coach);
	            FootballManager fmng;
	            TeamTitle();
	            fmng.insert_team_from_file();
	            fmng.find_team_by_coach(coach);
	            system("pause");
	        }
	        else if (chon == 5)
	        {
	            string location;
	            cout<<"Nhập tên địa phương :";
	            fflush(stdin);
	            getline(cin,location);
	            FootballManager fmng;
	            fmng.insert_team_from_file();
	            fmng.find_team_by_location(location);
	            system("pause");
	        }
	        
	        else if (chon == 6)
	        {
	            Team team;
	            int n;
	            cout<<"Nhập số đội bóng cần thêm :";
	            cin>>n;
	            for (int i = 0; i < n; i++)
	            {
	                cout<<"Nhập thông tin đội bóng thứ "<<i+1<<endl;
	                team.insert_inf();
	                team.insert_team_to_file();
	                cout<<"====================================\n";
	
	            }
	            cout<<"đã thêm xong";
	            system("pause");
	
	        }
	        else if (chon == 7)
	        {
	            string namedb;
	            cout<<"Nhập tên đội bóng : ";
	            fflush(stdin);
	            getline(cin,namedb);
	            FootballManager fmng;
	            fmng.insert_team_from_file();
	            string idteam = fmng.get_idteam_by_nameTeam(namedb);
	            Team team;
	            cout<<"Danh sách đội bóng của đội bóng : "<<namedb<<endl;
	            team.find_player_of_id_team(idteam);
	            system("pause");
	        }
	        else if (chon == 8)
	        {
	            string name;
	            cout<<"Nhập tên đội bóng cần xóa :";
	            fflush(stdin);getline(cin,name);
	            FootballManager fmng;
	            fmng.insert_team_from_file();
	            fmng.removeTeambyname(name);
	            system("pause");
	        }
	        else if (chon == 9)
	        {
	            FootballManager fmng;
	            fmng.Teamxuatcsv();
	            cout<<"Đâ xuất file thành công ";
	            system("pause");
	        }
	        
	        else if (chon == 0){
	            break;
	        }
	        else
	            cout<<"Lựa chọn không hợp lệ , vui lòng kiểm tra lại ";
	
	    } while (chon!=0);
	    
	}

int main() {
    int dem = 0;
	ofstream input("D:\\DanhsachSoTietKiem.txt", ios::app);
    	if(input.is_open() == NULL){
    		cout << "Khong mo duoc file !";
		}
		input << "                                     Danh sach so Tiet Kiem                                          " << endl;
    	input << "  =================================================================================================  " << endl;
    	
    	input <<	" STT. |Ma khach hang|       Ho va Ten       |    So CMT    |  Tien Gui  |  Ngay Lap So  |Lai Suat| Ky Han |"<< endl << "--------------------------------------------------------------------------------------------------------" << endl;
    	input.close();

	NganHang nganHang("Vietcombank", "123 Le Duan", "1234567890", "0123456789", "abc@nganhang.com");
    
	int choice;
    do {
        cout << "==== MENU ====" << endl;
        cout << "1. Them so tiet kiem" << endl;
        cout << "2. Tinh lai suat cua mot so tiet kiem" << endl;
        cout << "3. Tinh tong tien lai cua ngan hang" << endl;
        cout << "4. Xuat danh sach cac so tiet kiem" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
				nganHang.nhapSoTietKiem();
				ghiFile(dem);
				dem++;
				break;
            case 2:
                int index;
                cout << "Nhap so thu tu cua so tiet kiem: ";
                cin >> index;
                nganHang.tinhLaiSuat(index - 1);
                break;
            case 3:
                nganHang.tinhTongLaiSuat();
                break;
            case 4:
                nganHang.xuatDanhSachSoTietKiem();
                break;
            case 0:
                cout << "Cam on ban da su dung chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
