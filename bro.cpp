#include<iostream>
using namespace std;
//Amit [The Bro Programmer]
class Error
{
public:
bool hasError()
{
return false;
}
string getError()
{
return "";
}
};
class Request
{
};
class Response
{
public:
void setContentType(string contentType)
{
//do nothing right now
}
Response & operator<<(string content)
{
//right now do nothing
return *this;
}
};

class Bro
{
public:
void setStaticResourcesFolder(string staticResourcesFolder)
{
//do nothing right now
}
void get(string urlPattern,void (*callBack)(Request &,Response &))
{
//do nothing right now
}
void listen(int portNumber,void (*callback)(Error &))
{
//do nothing right now
}
};
//Bobby [The Web Application Developer - User of Bro Web Server]

int main()
{
Bro bro;
bro.setStaticResourcesFolder("whatever");

bro.get("/",[](Request &request,Response &response){
const char *html=R"""(
<!DOCTYPE HTML>
<html lang='en'>
<head>
<meta charset='utf-8'>
<title>Whatever</title>
</head>
<body>
<h1>Welcome</h1>
<h3>Administration</h3>
<a href='getCustomers'>Customers List</a>
</body>
</html>
)""";
response.setContentType("text/html"); //setting MIME type
response<<html;
});
bro.get("/getCustomers",[](Request &request,Response &response){
const char *html=R"""(
<!DOCTYPE HTML>
<html lang='en'>
<head>
<meta charset='utf-8'>
<title>Whatever</title>
</head>
<body>
<h1>List of Customers</h1>
<ul>
<li>Ramesh</li>
<li>Suresh</li>
<li>Mohan</li>
</ul>
<a href='/'>Home</a>
</body>
</html>
)""";
response.setContentType("text/html"); //setting MIME type
response<<html;
});

bro.listen(6060,[](Error &error){
if(error.hasError())
{
cout<<error.getError();
return;
}
cout<<"Bro HTTP Server is ready to accept request on port 6060"<<endl;
});
return 0;
}