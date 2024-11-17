#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node(int val): data(val), next(nullptr){}
};

class List{
	private:
		Node* head;
	public:
		List(): head(nullptr){}
		~List(){
			while(head){
				Node* temp = head;
				head = head -> next;
				delete temp;
			}
		}
		void add(int val){
			Node* newNode = new Node(val);
			newNode -> next = head;
			head = newNode;
		}
		Node* gethead() const{
			return head;
		}
		void print(ofstream& file) const{
			Node* temp = head;
			while(temp){
				file << temp -> data << " ";
				temp = temp -> next;
			}
		}
};
class graph{
	private:
		int V;
		List* adj;
		void dfs(int v, vector<bool>& visited){
			visited[v] = true;
			Node* curr = adj[v].gethead();
			while(curr){
				if(!visited[curr -> data]){
					dfs(curr -> data, visited);
				}
				curr = curr -> next;
			}
		}
	public:
		graph(int v = 0): V(v), adj(nullptr){
			if(v > 0){
				adj = new List[v];
			}
		}
		~graph(){
			if(adj){
				delete[] adj;
			}
		}
		void addEgde(int v, int w){
			adj[v].add(w);
			adj[w].add(v);
		}
		void readfile(const string& file_name){
			ifstream infile(file_name);
			if (!infile.is_open()) {
            	cerr << "K the doc file!" << endl;
            	return;
        	}
			int E;
			infile >> V >> E;
			delete[] adj;
			adj = new List[V];
			int v, e;
			while(infile >> v >> e){
				addEgde(v, e);
			}
			infile.close();
			cout << "Doc file thanh cong!" << endl;
		}
		void writefile(const string& file_name){
			ofstream file(file_name);
			if(!file.is_open()){
				cerr << "K the mo file! " << endl;
				return;
			}
			for(int i = 0; i < V; ++i){
				file << i << ": ";
				adj[i].print(file);
				file << endl;
			}
			file.close();
			cout << "Ghi file thanh cong!"<< endl;
	   	}
	
		int ConnectComponents(){
			vector<bool> visited(V, false);
			int count = 0;
			for(int i = 0; i < V; ++i){
				if(!visited[i]){
					dfs(i, visited);
					++count;
				}
			}
			return count;
		}
		
		bool isPath(int start, int end){
			if(start == end) return true;
			vector<bool> visited(V, false);
			queue<int> q;
			q.push(start);
			visited[start] = true;
			while(!q.empty()){
				int v = q.front();
				q.pop();
				Node* curr = adj[v].gethead();
				while(curr){
					if(curr -> data == end) return true;
					if(!visited[curr -> data]){
						q.push(curr -> data);
						visited[curr -> data] = true;
					}
					curr = curr -> next;
				}
			}
			return false;
		}
};
int main(){
	graph g;
	string doc, xuat;
	cout << "Nhap file de doc va de xuat: ";
	cin >> doc >> xuat;
	g.readfile(doc);
	g.writefile(xuat);
	int dem = g.ConnectComponents();
	cout << "So tp lien thong cua do thi la: " << dem << endl;
	int start, end;
	cout << "Nhap 2 dinh b muon ktra duong di: ";
	cin >> start >> end;
	if(g.isPath(start, end)){
		cout << "Ton tai duong di giua " << start << " va " << end << endl;
    } 
	else{
        cout << "K ton tai duong di giua " << start << " va " << end << endl;
    }
	
}
