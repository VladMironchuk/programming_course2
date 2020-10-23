class Employer {
	virtual void moneyPerLife() = 0;
	virtual void showJob() = 0;
};

class Manager : public Employer {
private:
	double wage;
public:
	Manager(double wage_) : wage(wage_) {};
	void showJob();
	void moneyPerLife();
};

class Admin : public Employer {
private:
	double wage;
public:
	Admin(double wage_) : wage(wage_) {};
	void showJob();
	void moneyPerLife();
};

class Programmer : public Employer {
private:
	double wage;
public:
	Programmer(double wage_) : wage(wage_) {};
	void showJob();
	void moneyPerLife();
};