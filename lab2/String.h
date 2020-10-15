class String {
private:
	int stringLength;
	char* string;
public:
	String();
	String(char* string, int n) : string(string), stringLength(n) {};
	String(const String& string1);
	~String();
	void setString();
	void setString(char *str);
	void setStringLength(int l);
	void setStringLength();
	String stringConcatenation(String string1);
	void compaireStrings(String string1);
	char getSymbol(int n);
	char* getString();
	int getStringLength();
	void showString();
	String operator+(String string1);
	String& operator=(const String string1);
	String operator+=(String string1);
	bool operator<(String string1);
	bool operator>(String string1);
	char& operator[](int i);
	void sortMassiveByFirtsLetter(String list[], int n);
	void sortMassiveByLengths(String list[], int n);
};