
#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class clsString
{

private:
    string _sValue;
    char _charValue;

public:

    clsString()
    {
        _sValue = "";
    }

    clsString(string Value)
    {
        _sValue = Value;
    }


     void SetValue(string Value) {
        _sValue = Value;
    }

    string GetValue() {
        return _sValue;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;
     void SetCharValue(char charValue) {
        _charValue = charValue;
    }
    char GetCharValue() {
        return _charValue;
    }
    __declspec(property(get = GetCharValue, put = SetCharValue)) char charValue;

/*    static short CountWords(string S1)
    {

        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until position and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }

    short CountWords()
    {
        return CountWords(_sValue);
    };
	*/
    //------------------------------

	static string ReadString()
	{
		string s1;
		cout << "Please Enter Your String:\n";
		getline(cin, s1);
		return s1;
	}
	static string ReadString(string Message)
	{
		string s1;
		cout << Message;
		getline(cin, s1);
		return s1;
	}
	static char ReadChar()
	{
		char Ch1;
		cout << "Please Enter a Character?\n";
		cin >> Ch1;
		return Ch1;
	}
	static void PrintFirstLetterOfEachWord(const string& s1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < s1.length(); i++)
		{
			if (s1.at(i) != ' ' && isFirstLetter)
				cout << s1.at(i) << endl;
			isFirstLetter = (s1.at(i) == ' ');		// لو الحرف الحالي مسافة، يبقى الحرف اللي جاي احتمال يكون بداية كلمة
		}
	}
	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_sValue);
	}


	static string UpperFirstLetterOfEachWord(string s1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < s1.length(); i++)
		{
			if (s1.at(i) != ' ' && isFirstLetter)
				s1[i] = toupper(s1[i]);
			isFirstLetter = (s1[i] == ' ');		// لو الحرف الحالي مسافة، يبقى الحرف اللي جاي احتمال يكون بداية كلمة
		}
		return s1;
	}
	void  UpperFirstLetterOfEachWord()
	{
		// no need to return value , this function will directly update the object value  
		_sValue = UpperFirstLetterOfEachWord(_sValue);
	}

	/*string UpperFirstLetterOfEachWord()
	{ // هنا بتعود بنسخة من الكائن مما يتيح استخدام النص الأصلي في عمليات أخرى لاحقاً.
		return UpperFirstLetterOfEachWord(_sValue);
	}*/
	string GetUpperFirstLetterOfEachWord() 
	{// الاسم يوضح أنها تعود بنسخة ولا تغير الأصل
		return UpperFirstLetterOfEachWord(_sValue);
	}


	static string lowerFirstLetterOfEachWord(string s1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < s1.length(); i++)
		{
			if (s1.at(i) != ' ' && isFirstLetter)
				s1[i] = tolower(s1[i]);
			isFirstLetter = (s1[i] == ' ');		// لو الحرف الحالي مسافة، يبقى الحرف اللي جاي احتمال يكون بداية كلمة
		}
		return s1;
	}
	/*string lowerFirstLetterOfEachWord()
	{
		return lowerFirstLetterOfEachWord(_sValue);
	}*/
	void  lowerFirstLetterOfEachWord()
	{


		// no need to return value , this function will directly update the object value  
		_sValue = lowerFirstLetterOfEachWord(_sValue);
	}


	static string UpperAllString(string s1)
	{

		for (short i = 0; i < s1.length(); i++)
			s1[i] = toupper(s1[i]);
		return s1;
	}
/*	 string UpperAllString()
	{
		 return UpperAllString(_sValue);
	}*/

	void  UpperAllString()
	{
		_sValue = UpperAllString(_sValue);
	}

	static string lowerAllString(string s1)
	{

		for (short i = 0; i < s1.length(); i++)
			s1[i] = tolower(s1[i]);
		return s1;
	}
	/*
	string lowerAllString()
	{
		return lowerAllString(_sValue);
	}
	*/
	
	void  LowerAllString()
	{
		_sValue = lowerAllString(_sValue);
	}


	static char InvertLetterCase(char c)
	{
		return (islower(c) ? toupper(c) : tolower(c));
	}
	char InvertLetterCase()
	{
		return InvertLetterCase(_charValue);
	}

	static string InvertAllStringLettersCase(string s)
	{
		for (short i = 0; i < s.length(); i++)
		{
			s[i] = InvertLetterCase(s[i]);
		}
		return s;
	}
	string GetInvertAllStringLettersCase()
	{
		return InvertAllStringLettersCase(_sValue);
	}
	void InvertAllStringLettersCase()
	{
		_sValue = InvertAllStringLettersCase(_sValue);
	}
	//GetCapitalAndSmallLettersCount
	static pair<int, int> CountLettersCapitalAndSmall(const string& s1)
	{
		int Capital = 0, small = 0;
		for (short i = 0; i < s1.length(); i++)
		{
			if (isupper(s1[i])) Capital++;
			else if (islower(s1[i])) small++;
		}
		return { Capital, small };
		//call
		//	auto [Capital, small] = CapitalAndSmallLettersCount(s1);
	}
	pair<int, int> CountLettersCapitalAndSmall()
	{
		return CountLettersCapitalAndSmall(_sValue);
	}
	enum enCountLetters {
		SmallLetters = 0, CapitalLetters = 1, PunctLetters = 2, Digits = 3, Spaces = 4, AllLetters = 5
	};
	static short CountLetters(const string& s1, enCountLetters WhatToCount = enCountLetters::AllLetters)
	{

		if (WhatToCount == enCountLetters::AllLetters) return s1.length();
		short Counter = 0;

		/* using for loop
		for (short i = 0; i < s1.length(); i++)
	{
		if (WhatToCount == enCountLetters::SmallLetters && islower(s1[i]))
			Counter++;
		else if (WhatToCount == enCountLetters::CapitalLetters && isupper(s1[i]))
			Counter++;
		else if (WhatToCount == enCountLetters::PunctLetters && ispunct(s1[i]))
			Counter++;
		else if (WhatToCount == enCountLetters::Digits && isdigit(s1[i]))
			Counter++;
		else if (WhatToCount == enCountLetters::Spaces && s1[i] == ' ')
		Counter++;
	}
		*/
		switch (WhatToCount)
		{
		case SmallLetters:
			for (const char& c : s1)
				if (islower(c)) Counter++;
			break;
		case CapitalLetters:
			for (const char& c : s1)
				if (isupper(c)) Counter++;
			break;
		case PunctLetters:
			for (const char& c : s1)
				if (ispunct(c)) Counter++;
			break;
		case Digits:
			for (const char& c : s1)
				if (isdigit(c)) Counter++;
			break;
		case Spaces:
			for (const char& c : s1)
				if (c == ' ') Counter++;
			break;
		case AllLetters:
			return s1.length();
		default:
			return s1.length();
		}

		return Counter;
	}
	short CountLetters(enCountLetters WhatToCount = enCountLetters::AllLetters)
	{
		return CountLetters(_sValue, WhatToCount);
	}

	static short CountLetterCharacter(string s1, char c1, bool MatchCase = true)
	{
		short count = 0;
		for (short i = 0; i < s1.length(); i++)
		{
			if (MatchCase)
			{
				if (s1[i] == c1) count++;
			}
			else
			{
				if (tolower(s1[i]) == tolower(c1)) count++;
			}
		}
		return count;
	}
	short CountLetterCharacter(char c1, bool MatchCase = true)
	{
		return CountLetterCharacter(_sValue, c1, MatchCase);
	}

	static bool isVowel(char ch)
	{
		ch = tolower(ch);

		switch (ch)
		{
		case 'a':case 'e':case 'i':case 'o':case 'u': return true;
		default: return false;
		}
		//static char arrVowels[5] = { 'a', 'e', 'i', 'o', 'u' };
	//bool isVowel(char ch)
	//{
	//	ch = tolower(ch);
	//	
	//	for (short i = 0; i < 5; i++)
	//		if (arrVowels[i] == ch) return true;
	//	
	//	return false;
	//}
	}
	bool isVowel()
	{
		return isVowel(_charValue);
	}

	static short CountVowels(string s1)
	{
		short counter = 0;
		for (short i = 0; i < s1.length(); i++)
		{
			if (isVowel(s1[i])) counter++;
		}return counter;
	}
	short CountVowels()
	{
		return CountVowels(_sValue);
	}

	static void PrintAllVowels(string s1)

	{
		for (short i = 0; i < s1.length(); i++)
			if (isVowel(s1[i])) cout << s1[i] << "  ";
	}
	void PrintAllVowels()
	{
		PrintAllVowels(_sValue);
	}

	static void PrintEachWordInStringUsingForLoop(string s1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ') cout << s1[i];
			if (s1[i] == ' ' && !isFirstLetter)
				cout << endl;
			isFirstLetter = (s1[i] == ' ');		// لو الحرف الحالي مسافة، يبقى الحرف اللي جاي احتمال يكون بداية كلمة

		}
	}
	void PrintEachWordInStringUsingForLoop()
	{
		return PrintEachWordInStringUsingForLoop(_sValue);
	}

	static void PrintEachWordInString(string S1)
	{
		string delim = " "; // delimiter
		cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length()); /* erase() until
			positon and move to next word. */
		}
		if (S1 != "")
		{
			cout << S1 << endl; // it print last word of the string.
		}
	}
	void PrintEachWordInString()
	{
		return PrintEachWordInString(_sValue);
	}


	static short CountWords(string s1) 
	{
		string delim = " ", sWord = "";
		short pos = 0, count = 0;

		while ((pos = s1.find(delim)) != std::string::npos)
		{
			sWord = s1.substr(0, pos);
			if (sWord != "") count++;

			s1.erase(0, pos + delim.length());
		}
		if (s1 != "") count++;
		return count;
	}
	short CountWords()
	{
		return CountWords(_sValue);
	}

	static vector<string> Split(string S1, string Separator)
	{
		vector<string> vString;
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(Separator)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + Separator.length()); /* erase() until
			position and move to next word. */
		}
		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}
		return vString;
	}
	vector<string> Split(string Separator)
	{
		return Split(_sValue, Separator);
	}

	void Print()
	{
		cout << _sValue << endl;
	}
	string PrintToString()
	{
		return _sValue;
	}

	static void PrintVectorString(const vector<string>& vString)
	{
		for (const string& s : vString)
			cout << s << endl;
	}
	void PrintVectorString()
	{	// ننشئ فيكتور سريع يحتوي على نص الكائن الحالي ونمرره للدالة الساكنة
		PrintVectorString(vector<string>{_sValue});
	}

	static string TrimLeft(string S1)
	{
		// 1. بيمشي من أول حرف (index 0) لحد آخر حرف
		for (short i = 0; i < S1.length(); i++)
		{
			// 2. أول ما يقابل "أول حرف" مش مسافة
			if (S1[i] != ' ')
			{
				// 3. هنا السر! بيستخدم دالة substr
				return S1.substr(i, S1.length() - i);
			}
		}
		return ""; // لو الجملة كلها مسافات
	}
	string TrimLeft()
	{
		return TrimLeft(_sValue);
	}

	static string TrimRight(string S1)
	{
		if (S1.empty()) return "";
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ') // أول ما يقابل حرف من ناحية اليمين
			{
				return S1.substr(0, i + 1); // اقطع من الصفر لحد المكان ده
			}
		}
		return ""; // لو الجملة كلها مسافات

	}
	string TrimRight()
	{
		return TrimRight(_sValue);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}
	string Trim()
	{
		return Trim(_sValue);
	}

	static string TrimLeftUsingErase(string& s1)
	{

		for (short i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ') return s1.erase(0, i); // تعديل مباشر في الذاكرة
		}
		// لو وصل هنا معناه إن الجملة كلها مسافات
		return s1.erase(0, s1.length()); // عشان لو الجملة فراغات فقط ترجع صفر مسافات
	}
	void TrimLeftUsingErase()
	{ // الدالة تعود بـ void لأن الـ _sValue تم تنظيفها داخلياً بنجاح ^_^
		TrimLeftUsingErase(_sValue);
	}

	static string TrimRightUsingErase(string& s1)
	{
		if (s1.empty()) return "";
		for (short i = s1.length() - 1; i >= 0; i--)
		{
			if (s1[i] != ' ') return s1.erase(i + 1, s1.length());// تعديل مباشر في الذاكرة
		}
		return s1.erase(0, s1.length()); // عشان لو الجملة فراغات فقط ترجع صفر مسافات
	}
	/*string TrimRightUsingErase()
	{
		return TrimRightUsingErase(_sValue);
	}*/
	void TrimRightUsingErase()
	{
		TrimRightUsingErase(_sValue);
	}

	static string TrimAllUsingErase(string& s1)
	{
		TrimLeftUsingErase(s1);
		return TrimRightUsingErase(s1);
	}
	void TrimAllUsingErase()
	{
		TrimLeftUsingErase(_sValue);  
		TrimRightUsingErase(_sValue); 
	}

	static string JoinString(const vector<string>& vString, string Delim)
	{
		if (vString.empty()) return "";
		string s1 = "";
		for (const string& s : vString)
			s1 += s + Delim;
		return s1.substr(0, s1.length() - Delim.length());
	}
	string JoinString(string Delim)
	{
		return JoinString(vector<string>{_sValue},Delim);
	}

	static string JoinString(string arr[], short length, string Delim)
	{
		string s1 = "";
		for (short i = 0; i < length - 1; i++)
		{
			s1 += arr[i] + Delim;
		}
		return s1 + arr[length - 1]; // بضيف آخر عنصر بدون الفاصل
	}
	string JoinString(string arr[], short length)
	{// لم أضع الفاصل من الخارج، بل نستخدم النص الداخلي للكائن (_sValue) كفاصل
		// تفويض الدالة الساكنة مع استخدام نص الكائن كفاصل Delim
		return JoinString(arr, length, _sValue);
	}

	static string ReverseWordsInString(string s1, string delim)
	{
		vector<string> vString = Split(s1, delim);
		if (vString.empty()) return "";
		string s2 = "";
		for (int i = vString.size() - 1; i >= 0; i--)
		{
			s2 += vString[i] + delim;
		}
		return (s2.substr(0, s2.length() - delim.length()));
	}
	string ReverseWordsInString(string delim)
	{
		return ReverseWordsInString(_sValue, delim);
	}
	string ReverseWordsInString()
	{
		return ReverseWordsInString(_sValue, " ");
	}

	static vector<string> ReverseWordsInVector(string s1, string delim = " ")
	{
		vector<string> vString = Split(s1, " ");
		string s2 = "";
		vector<string> v2;
		for (int i = vString.size() - 1; i >= 0; i--)
		{
			v2.push_back(vString[i]);
		}
		vString.clear();
		return (v2);
	}
	vector<string> ReverseWordsInVector(string delim = " ")
	{
		return ReverseWordsInVector(_sValue, delim);
	}

	static string ReplaceStringUsingBuiltinFunction(string s1, string oldString, string updateTo)
	{
		short pos = s1.find(oldString);

		while (pos != std::string::npos)
		{
			s1.replace(pos, oldString.length(), updateTo);
			pos = s1.find(oldString);
		}
		return s1;
	}
	string ReplaceStringUsingBuiltinFunction(string oldString, string updateTo)
	{
		return ReplaceStringUsingBuiltinFunction(_sValue, oldString, updateTo);
	}

	static string ReplaceStringUsingIterator(string s1, string OldWord, string updateTo, string Separator = " ", bool matchCase = true)
	{
		vector<string> vString = Split(s1, Separator);
		vector<string>::iterator iter;
		for (iter = vString.begin(); iter != vString.end(); iter++)
		{
			if (matchCase)
			{
				if (*iter == OldWord) *iter = updateTo;
			}
			else
			{
				if (lowerAllString(*iter) == lowerAllString(OldWord)) *iter = updateTo;
			}
		}

		return JoinString(vString, Separator);
	}
	string ReplaceStringUsingIterator(string OldWord, string updateTo, string Separator = " ", bool matchCase = true)
	{
		return ReplaceStringUsingIterator(_sValue, OldWord, updateTo, Separator, matchCase);
	}

	static string ReplaceStringUsingSplit(string s1, string OldWord, string updateTo, string Separator = " ", bool matchCase = true)
	{
		vector <string >vString = Split(s1, Separator);
		for (string& s : vString)
		{
			if (matchCase)
			{
				if (s == OldWord) s = updateTo;
			}
			else
			{
				if (lowerAllString(s) == lowerAllString(OldWord)) s = updateTo;
			}
		}
		return JoinString(vString, Separator);
	}
	string ReplaceStringUsingSplit(string OldWord, string updateTo, string Separator = " ", bool matchCase = true)
	{
		return ReplaceStringUsingSplit(_sValue, OldWord, updateTo, Separator, matchCase);
	}

	static string RemoveAllPunctuationsAndPutSpace(string s1)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (ispunct(s1[i])) s1[i] = ' '; // O(N)
		}
		return s1;
	}
	string RemoveAllPunctuationsAndPutSpace()
	{
		return RemoveAllPunctuationsAndPutSpace(_sValue);
	}
	static string RemovePunctuationsFromString(string s1)
	{
		string s2;
		for (int i = 0; i < s1.length(); i++)
		{
			if (!ispunct(s1[i])) s2 += s1[i]; // O(N)
		}
		return s2;
	}
	string RemovePunctuationsFromString()
	{
		return RemovePunctuationsFromString(_sValue);
	}

};