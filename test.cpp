#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
vector<PII>segs;
const int eps=1e-3;
const int N=1e6+10;
int n,q[N],temp[N],a[N],b[N];
//1.���� 
//���С��x���ұߴ���x�������㽻�� 
void quick_sort(int a[],int l,int r){
	if(l>=r)return ;
	int i=l-1,j=r+1,x=q[(l+r)>>1];
	while(i<j){
		while(q[++i]<x);
		while(q[--j]>x);
		if(i<j)swap(q[i],q[j]);
	}
	quick_sort(a,l,j),quick_sort(a,j+1,r);	
} 
//���ã���k����� 
int kth(int a[],int l,int r,int k){
	if(l>=r)return q[l];
	int i=l-1,j=r+1,x=q[(l+r)>>1];
	while(i<j){
		while(q[++i]<x);
		while(q[--j]>x);
		if(i<j)swap(q[i],q[j]);
	}
	int M=j-l+1;//ע�⣺������j-l+1��������r-l+1�� 
	if(M>=k)return kth(a,l,j,k);
	else return kth(a,j+1,r,k-M);	
}
//2.�鲢���� 
void merge_sort(int a[],int l,int r){
	if(l>=r)return;//�ݹ���ֹ����ǧ����© 
	int mid=(l+r)>>1;
	merge_sort(a,l,mid),merge_sort(a,mid+1,r); 
	int i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r){//ע�����ﶼ�е��ڣ��� 
		if(a[i]<a[j])
		temp[k++]=a[i++];
		else temp[k++]=a[j++];
	}
	while(i<=mid)temp[k++]=a[i++];
	while(j<=r)temp[k++]=a[j++];
	for(int i=l,j=0;i<=r;i++,j++){
		a[i]=temp[j];
	}
} 
 //���ã�����Ե�����
int reverse_number(int a[],int l,int r){
	if(l>=r)return 0;//�ݹ���ֹ����ǧ����© 
	int mid=(l+r)>>1;
	int cnt=reverse_number(a,l,mid)+reverse_number(a,mid+1,r); 
	int i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r){//ע�����ﶼ�е��ڣ��� 
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}
		else {
			temp[k++]=a[j++];
			cnt+=mid-i+1;
		}
	}
	while(i<=mid)temp[k++]=a[i++];
	while(j<=r)temp[k++]=a[j++];
	for(int i=l,j=0;i<=r;i++,j++){
		a[i]=temp[j];
	}
	return cnt;
} 
//3.���� 
//3.1 ��x ������Ҳ��ӣ� 
int binary(int a[],int l,int r,int x){
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]==x)return mid;
		else if(a[mid]>x) r=mid;
		else l=mid+1;
	}
	return -1;
} 
//3.2 �ҵ�һ�����ڵ���x��λ��
int upper_equal(int a[],int l,int r,int x){
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]>=x)r=mid;
		else l=mid+1;
	}
	return l;
} 
//3.3 �ҵ�һ������x��λ��
int upper(int a[],int l,int r,int x){
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]>x)r=mid;
		else l=mid+1;
	}
	return l;
} 
// 3.4 ����x��λ�÷�Χ 
void range(int a[],int x){
	int l=0,r=n-1;
	while(l<r){
		//�ҵ�һ�����ڵ���x��λ�� 
		int mid=(l+r)>>1;
		if(a[mid]>=x)r=mid;
		else l=mid+1;
	}
	if(a[l]!=x)cout<<"start:-1 end:-1"<<endl;
	else{
		int start=l;
		l=0,r=n-1;
		while(l<r){
			//�ҵ�һ������x��λ�� 
			int mid=(l+r)>>1;
			if(a[mid]>x)r=mid;
			else l=mid+1;
		}
		int end=l-1;
		
		cout<<"start:"<<start<<" end:"<<end<<endl;
	}
	
} 
// 4.����������(����mid) 
int binary_double(int a[],int l,int r,int x){
	while(r-l>eps){
		int mid=(l+r)>>1;
		if(a[mid]>=x)r=mid;
		else l=mid;
	}
	return -1;
} 
//4.1���ã���x�����η��� 
double sqrt3(double x){
	double l=-10000,r=10000;
    while((r-l) > 1e-8){
        double mid=(l+r)/2;
        if(mid*mid*mid >= n) r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(6)<<l;
} 
//5.1�߾��ȼӷ�    0~n-1:���λ~���λ 
vector<int>add(vector<int>&a,vector<int>&b){
	if(a.size()<b.size())return add(b,a);
	vector<int>c;
	int t=0;
	for(int i=0;i<a.size();i++){
		t+=a[i];
		if(i<b.size())t+=b[i];
		c.push_back(t%10);
		t/=10;
	}
	if(t)c.push_back(t);//��Ҫ������󻹿��ܽ�λ 
	return c;
}
//5.2����   a>=b 
vector<int>sub(vector<int>&a,vector<int>&b){
	vector<int>c;
	int t=0;
	for(int i=0;i<a.size();i++){
		t=a[i]-t;
		if(i<b.size())t-=b[i];
		c.push_back((t+10)%10);//ע������Ҫ����10��Ϊt����Ϊ���� 
		if(t<0)t=1;
		else t=0;	
	}
	while(c.size()>1&&c.back()==0)c.pop_back();//ȥ��ǰ���� 
	return c;
}
bool cmp(vector<int>&a,vector<int>&b){
	if(a.size()!=b.size())return a.size()>b.size();
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i])return a[i]>b[i];
	}
	return true;
}
//4.3�˷�
 vector<int> mul(vector<int> &a, int b){
	vector<int>c;
	int t=0;
	for(int i=0;i<a.size()||t;i++){
	//ע������ͼӷ���������ֹ������i>=a.size()&&t=0 ��������ʵ�ֽ�λ 
		if(i<a.size())t+=a[i]*b;
		c.push_back(t%10);
		t/=10;
	}
	while(c.size()>1&&c.back()==0)c.pop_back();//ȥ��ǰ����  
	return c;
 }
 //4.4����
 //�Դ��� 
vector<int> div1(vector<int> &a, int b){
	vector<int>c;
	int t=0;
	for(int i=a.size()-1;i>=0;i--){
		while(i>0&&t*10+a[i]<b)t=t*10+a[i--];//��ģ��ĳ������� ��ʹ��ѭ���ҵ����Գ��ĵ�һ��λ�� 
		t=t*10+a[i];
		cout<<"t:"<<t<<endl; 
		c.push_back(t/b);
		t=t%b;		
	}
	reverse(c.begin(),c.end());
	while(c.size()>1&&c.back()==0)c.pop_back();//ȥ��ǰ����  
	return c;
 }
 vector<int> div(vector<int> &a, int b){
	vector<int>c;
	int t=0;
	for(int i=a.size()-1;i>=0;i--){
		t=t*10+a[i];
		c.push_back((t/b)%10);
		t=t%b;		
	}
	reverse(c.begin(),c.end());
	while(c.size()>1&&c.back()==0)c.pop_back();//ȥ��ǰ����  
	return c;
 }  
// 5.1ǰ׺��
//һά 
void preSum1(int a[],int l,int r){
	//�����1��ʼ�洢�����Ͳ���Ҫ����temp��0λ�ó�ʼ������
	for(int i=1;i<=n;i++)temp[i]=temp[i-1]+a[i]; 
	cout<<"l~r�ĺ�Ϊ��"<<temp[r]-temp[l-1]<<endl;
} 
//��ά 
//void preSum2(int n,int m,int l1,int r1,int l2,int r2){
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
//		}
//	}
//	cout<<"(l1,r1)->(l2,r2)�ĺ�Ϊ��"<<s[l2][r2]-s[l1][r1]<<endl;
//} 
//5.2���
//һά 
void insert1(int l,int r,int c){
	temp[l]+=c;
	temp[r+1]-=c;
}
void su1(int a[],int l,int r,int c){
	for(int i=1;i<=n;i++)insert1(i,i,q[i]);
	for(int i=1;i<=n;i++)insert1(l,r,c);
	//��������ǰ׺��temp[1~i]�� ԭ����Ԫ��q[i] 
	for(int i=1;i<=n;i++)temp[i]+=temp[i-1];
	for(int i=1;i<=n;i++)cout<<temp[i]<<" ";
	cout<<endl;
	
} 
//��ά 
//void insert(int x1,int y1,int x2,int y2,int c){
//	s[x1][y1]+=c;
//	s[x1+1][y1]-=c;
//	s[x1][y1+1]-=c;
//	s[x2+1][y2+1]+=c;
//}
//void su2(int n,int m,int l1,int r1,int l2,int r2){
//	cin>>n>>m;
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=m;j++) cin>>a[i][j];
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=m;j++) insert(i,j,i,j,a[i][j]);
//    int x1,y1,x2,y2,c;
//    cin>>x1>>y1>>x2>>y2>>c;
//    insert(x1,y1,x2,y2,c);
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=m;j++) s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++) cout<<s[i][j]<<" ";
//         cout<<endl;
//     }
//} 
//6.˫ָ�루ֻ�����ã� 
//6.1��������ظ������� 
//void longest(){
//	cin>>n;
//    for(int i=0;i<n;i++) cin>>a[i];
//    int res=0;
//    for(int i=0,j=0;i<n;i++){
//        s[a[i]]++;
//        //ά��һ�������ظ������������Ĵ��ڣ���ߣ�j���ұߣ�i��
//        while(s[a[i]]>1){
//            s[a[j]]--;
//            j++;
//        }
//        res=max(res,i-j+1);
//    }
//    cout<<res;
//} 
//6.2����Ԫ�ص�Ŀ���
//my solution
 void target1(){
 	int n,m,x;
 	cin>>n>>m>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0,j=m-1;i<n&&j>=0;i++){
    	if(a[i]+b[j]==x){
    		cout<<i<<" "<<j<<endl;
    		break;
		}else if(a[i]+b[j]<x)i++;
		else j--;
	}
    
 }
 //muban
 void target(){
 	int n,m,x;
 	cin>>n>>m>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0,j=m-1;i<n;i++){
    	//���ƶ�j��a[i]+b[j]<=x��λ�� ,�ڿ���i++ 
    	while(j>=0&&a[i]+b[j]>x)j--;
    	if(a[i]+b[j]==x){
    		cout<<i<<" "<<j<<endl;
    		break;
		}
	}
 }
 //6.3 b��a�Ķ����� 
 void isSon(){
 	int n,m,x;
 	cin>>n>>m>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0,j=0;j<m;j++){
    	while(b[j]!=a[i]&&i<n)i++;
    	if(i>=n){
    		cout<<"No"<<endl;
    		return;
		}
	}
	cout<<"Yes"<<endl;
 }
 //7.λ����
 //����һ�������λ1�������ֵ 
 int lowbit(int x){
 	return x&(-x);
 }
// ���ã�����������1�ĸ���
int count(int x){
	int cnt=0;
	while(x){
		x-=lowbit(x);
		cnt++;
	}
	return cnt;
}
//8.��ɢ��
 void lisan(vector<int>&alls){
 	sort(alls.begin(),alls.end());
 	alls.erase(unique(alls.begin(),alls.end()),alls.end());
	int l=0,r=alls.size()-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(alls[mid]>=n)r=mid;
		else l=mid+1;
	}
	cout<<r+1;
 } 
 //9.�ϲ�����
void merge(vector<PII>&segs){
	vector<PII>res;
	sort(segs.begin(),segs.end());
	int end=-2e9,start=-2e9; 
	for(auto s:segs){
		if(end<s.first){
			if(start!=-2e9)res.push_back({start,end});
			start=s.first;
			end=s.second;
		}else end=max(end,s.second);
	}
	if(start!=-2e9)res.push_back({start,end});
	segs=res;
} 
  
int main(){
	int n;
    cin>>n;
    while(n--){
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout<<segs.size();
//	cin>>n;
//	for(int i=0;i<n;i++)cin>>q[i];
//	quick_sort(q,0,n-1);
//	merge_sort(q,0,n-1); 
//	for(int i=0;i<n;i++)cout<<q[i]<<" ";
//	cout<<kth(q,0,n-1,3);
//	cout<<reverse_number(q,0,n-1);
//	cout<<binary(q,0,n-1,3);
//cout<<upper_equal(q,0,n-1,3);
//cout<<upper(q,0,n-1,3);
//
//cout<<sqrt3(10.0); 
//range(q,3);
//    cin>>a>>b;
//    vector<int> A,B;
//    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
//    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
//    cout<<"������"<<endl;
//    if(cmp(A,B)){
//        auto C=sub(A,B);
//        for(int i=C.size()-1;i>=0;i--) cout<<C[i];
//    }
//    else{
//        cout<<"-";
//        auto C=sub(B,A);
//        for(int i=C.size()-1;i>=0;i--) cout<<C[i];
//    }
//    cout<<endl<<"�ӷ�:"<<endl;
//    auto C=add(A,B);
//    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
//    cout<<endl<<"�˷�:"<<endl;
//    C=mul(A,2);
//    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
//    cout<<endl<<"����:"<<endl;
//    auto C=div1(A,2);
//    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
//    longest();
//isSon();
//cout<<count(20); 
	return 0;
}

