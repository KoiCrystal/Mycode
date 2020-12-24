#include<iostream>
#include<string>
using namespace std;
int longs(string s){               //密钥长度
    int len=s.length();
    for (int i=1;i<=10;i++)          //long
    {
        double CI=0;
        for (int j=1;j<=i;j++)          //lie
        {
            double ci[26]={0};
            int g=j-1;          //每列第一个的脚标
            int L=0;
            while(g<=len){
                ci[(int)s[g]-97]++;
                L++;
                g+=i;
            }
            double ic=0;
            for (int k=0;k<26;k++)      //每个ic
            {
                ic=ic+ci[k]*(ci[k]-1)/L/(L+1);
            }
            CI+=ic;
        }
        CI=CI/i;
        if (CI>0.0585&&CI<0.0725){
            return i;
            break;
        }
    }
}
string yiwei(string z){
    int len=z.length();
    for (int i=0;i<len;i++){
        int x=(int)z[i]-97;
        x+=25;
        if (x>25){
            x=x%26;
        }
        x=x+97;
        z[i]=(char)x;
    }
    return z;
}
string miyao(string s,int l){
    int len=s.length();
    string key="";
    for (int i=0;i<l;i++)       //分组
    {
        double CI[26]={0.082,0.015,0.028,0.043,0.127,0.022,0.02,0.061,0.07,0.002,0.008,0.04,0.024,0.067,0.075,0.019,0.001,0.06,0.063,0.091,0.028,0.01,0.023,0.001,0.02,0.001};
        string z="";
        int g=i;
        while(g<len){
            z=z+s[g];
            g+=l;
        }
        for (int j=0;j<26;j++)      //移位,从1开始，到最后不变,注意是减法移位
        {
            z=yiwei(z);
            double ci[26]={0};
            for (int k=0;k<z.length();k++){
                ci[(int)z[k]-97]++;
            }
            double M=0;
            for (int k=0;k<26;k++){
                M=M+CI[k]*ci[k]/z.length();
            }
            if(M>0.0585&&M<0.0725){
                int a=j;
                if (a+1>25){                //这个a是因为上面是从1而非0开始的，不能改变j的值，用a来替罪
                    a=a%26;
                }
                key=key+(char)(a+1+97);
                //cout<<(char)(a+1+97)<<endl;
            }
        }
    }
    return key;
}
char jiemi(char s,int k){
    int a=(int)s-97;
    a-=k;
    if (a<0){
        a+=26;
    }
    s=(char)(a+97);
    return s;
}
int main(){
    string y;
    string s;
    cout<<"请输入待解密字符串，大小写无所谓，有符号也行："<<endl;
    cin>>y;
    string z=y;
    bool daxie[z.length()]={0};
    for (int i=0;i<z.length();i++)          //这个函数如果遇到了符号会跳过
    {
        if (z[i]>='A'&&z[i]<='Z'){
            daxie[i]=1;
        }
        z[i]= tolower(z[i]);
    }
    for (int i=0;i<z.length();i++){         //过滤符号
        if (z[i]<'a'||z[i]>'z'){
                //这里本来有代码的
        }
        else{
            s=s+z[i];
        }
    }
    int l=longs(s);              //密钥长度
    if(l>10){
        cout<<"可能不是维吉尼亚"<<endl;
        return 0;
    }
    cout<<"密钥长度是："<<l<<endl;
    string key=miyao(s,l);
    cout<<"密钥是："<<key<<endl;
    int k=0;
    string mingwen="";
    for (int i=0;i<z.length();i++){         //解密
        if (k>=l){
            k=k%l;
        }
        if (y[i]>='a'&&y[i]<='z'){       //小写解密
            mingwen+=jiemi(y[i],(int)key[k]-97);
            k++;
        }
        else if (y[i]>='A'&&y[i]<='Z'){
            y[i]=tolower(y[i]);
            mingwen+=toupper(jiemi(y[i],(int)key[k]-97));       //直接输出toupper竟然是数字，不过无妨
            k++;
        }
        else{
            mingwen+=y[i];
        }
    }
    cout<<mingwen<<endl;
}
//测试数据
//CHREEVOAHMAERATBIAXXWTNXBEEOPHBSBQMQEQERBWRVXUOAKXAOSXXWEAHBWGJMMQMNKGRFVGXWTRZXWIAKLXFPSKAUTEMNDCMGTSXMXBTUIADNGMGPSRELXNJELXVRVPRTULHDNQWTWDTYGBPHXTFALJHASVBFXNGLLCHRZBWELEKMSJIKNBHWRJGNMGJSGLXFEYPHAGNRBIEQJTAMRVLCRREMNDGLXRRIMGNSNRWCHRQHAEYEVTAQEBBIPEEWEVKAKOEWADREMXMTBHH VKAKOEWADREMXMTBHHCHRTKDNVRZ TKDNVRZCHRCLQOHPWQAIIWXNRMGWOIIFKEE
//BZGTNPMMCGZFPUWJCUIGRWXPFNLHZCKOAPGLKYJNRAQFIUYRAVGNPANUMDQOAHMWTGJDXGOMPJPTKAAVZIUIWKVTUCWBWNFWDFUMPJWPMQGPTNWXTSDPLPMWJAXUHHXWPFXXGVAPFNTXVFKOYIRBOQJHCBVWVFYCGQFGUSUBDWVIYATJGTBNDKGHCTMTWIUEFJITVUGJHHIMUVJICUWYQWYGGUWPUUCWIFGWUANILKPHDKOSPJTTWJQOJHXLBJAPZHVQWPDYPGLLGDBCHTGIZCCMEGVIIJLIFFBHSMEGUJHRXBOQUBDNASPEUCWNGWSNWXTSDPLPMWJAIUHUMWPSYCTUWFBMIAMKVBNTDMQNBVDKILQSSDYVWVXIGDQFIBHSLEAVDBXGOLGDBCHTGIZVNFQFKTNGRWXUDCTGKWCOXIXKZPPFDZG
