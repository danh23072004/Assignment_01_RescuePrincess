#include "knight.h"

// Từ class Monster cho đến adventureToKoopa là của file knight.cpp

class Monster
{
public:
    double baseDamage[5] = { 1, 1.5, 4.5, 7.5, 9.5 };
    int levelO = 0;
    int damage = 0;
    //int shamanEffectLeft = 0;
    //int vajshEffectLeft = 0;
    int effectLeft = 0;
    bool isVajshEffect = false, isShamanEffect = false;

    void calculateLevelO(int eventNum)
    {
        int b = eventNum % 10;
        levelO = (eventNum > 6) ? (b > 5 ? b : 5) : b;
    }

    void calculateBaseDamage(int eventNum, int monsterNum)
    {
        damage = baseDamage[monsterNum - 1] * levelO * 10;
    }
    
    void applyShamanEffect(int &HP)
    {
        isShamanEffect = true;
        isVajshEffect = false;
        effectLeft = 4;
        if (HP < 5)
            HP = 1;
        else
            HP = HP / 5;
    }

    void applyVajshEffect(int &currentlevel, int &levelbefore)
    {
        isShamanEffect = false;
        isVajshEffect = true;
        effectLeft = 4;
        levelbefore = currentlevel;
        currentlevel = 1;
    }
};

class CalcMath
{
public:
    int SumOfSomeLargestOddNums(int num)
    {
        int sum = 0;
        for (int i = 0; i < num; i++)
        {
            sum += 100 - (1 + i * 2);
        }
        return sum;
    }
    
    bool isPrimeNum(int num)
    {
        if (num <= 1)
            return false;
        for (int i = 2; i * i <= num; i++) 
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    bool isSquare(int num)
    {
        int s = sqrt(num);
        return (s * s == num);
    }

    bool isFibonacci(int num)
    {
        return isSquare(5 * num * num + 4) || isSquare(5 * num * num - 4);
    }

    int findUpperNearestPrimeNum(int num)
    {
        do
        {
            num++;
        } 
        while (isPrimeNum(num) == false);
        return num;
    }

    int findLowerNearestFibonacci(int num)
    {
        if (num != 1)
        {
            do
            {
                num--;
            } 
            while (isFibonacci(num) != true);
        }
        return num;
    }

    int countNumDigit(int num)
    {
        return floor(log10(num) + 1);
    }

    int findFirstTwoDigitOfNum(int num)
    {
        int amountOfNumDigitNot13 = countNumDigit(num) - 2;
        return num = num / pow(10, amountOfNumDigitNot13);
    }

    void findLastPositionMaxMin(int a[100], int &maxPos, int &minPos, int size)
    {
        int max = a[0], maxCurrentPos = 0;
        int min = a[0], minCurrentPos = 0;
        for (int i = 1; i < size; i++)
        {
            if (a[i] >= max)
            {
                 max = a[i];
                 maxPos = i;
                 //maxCurrentPos = i;
                 //if (maxCurrentPos > maxPos) 
                 //{
                 //    maxPos = maxCurrentPos;
                 //}
            }
            if (a[i] <= min)
            {
                min = a[i];
                minPos = i;
                //minCurrentPos = i;
                //if (minCurrentPos > minPos)
                //{
                //    minPos = minCurrentPos;
                //}
            }
        }
    }

    void findFirstPositionMaxMin(int a[100], int& maxPos, int& minPos, int size)
    {
        int max = a[0];
        int min = a[0];
        for (int i = 1; i < size; i++)
        {
            if (a[i] > max)
            {
                max = a[i];
                maxPos = i;
            }
            if (a[i] < min)
            {
                min = a[i];
                minPos = i;
            }
        }
    }

    int compareTwoNums(int a, int b)
    {
        if (a > b)
            return -1;
        else if (a < b)
            return 1;
        else
            return 0;
    }

    void findMountainPeak(int a[100], int& topPosition, int& topValue, int size)
    {
        if (size == 1)
        {
            topPosition = 0;
            topValue = a[0];
        }
        else if (size == 2)
        {
            if (a[0] > a[1])
            {
                topPosition = 0;
                topValue = a[0];
            }
            else if (a[0] < a[1])
            {
                topPosition = 1;
                topValue = a[1];
            }
        }
        else
        {
            bool isIncreased;
            bool isMiddleSharp = false;
            int compare = compareTwoNums(a[0], a[1]);
            if (compare == 1)
            {
                isIncreased = true; // đang tăng
            }
            else if (compare == -1)
            {
                isIncreased = false; // đang giảm    
            }
            else if (compare == 0)
            {
                return;
            }
            for (int i = 1; i < size - 1; i++)
            {
                if (isIncreased == true && (a[i] > a[i + 1])) /* Trường hợp /\   */
                {
                    /* Trường hợp /\  (1) */
                    isIncreased = false;
                    isMiddleSharp = true;
                    topPosition = i;
                    topValue = a[i];
                }
                else if (isIncreased == true && (a[i] < a[i + 1])) 
                {
                    /* Trường hợp /  (2) */
                    if (((i + 1) == (size - 1)) && (isMiddleSharp == false))
                    {
                        // Lưu đỉnh cho trường hợp (2) nếu tại phần tử cuối cùng vẫn còn đúng
                        topPosition = size - 1;
                        topValue = a[size - 1];
                    }
                    continue;
                }
                else if (isIncreased == false && (a[i] > a[i + 1])) 
                {
                    /* Trường hợp \  (3) */
                    if ((i + 1) == (size - 1) && (isMiddleSharp == false))
                    {
                        // Lưu đỉnh trước cho trường hợp (3) nếu xảy ra
                        topPosition = 0;
                        topValue = a[0];
                    }
                    continue;
                }
                else if (isIncreased == false && (a[i] < a[i + 1]) || (a[i] = a[i + 1]))
                {
                    /* Trường hợp \/ hoặc -  (4) */
                    topPosition = -2;
                    topValue = -3;
                    break;
                }
            }

        }
    }
    
    void transformArrayMush3and4(int (&a)[100], int size)
    {
        for (int i = 0; i < size; i++)
        {
            a[i] = abs(a[i]);
            a[i] = (17 * a[i] + 9) % 257;
        }
    }

    void findSecondLargestNum(int a[100], int &value, int &pos ,int size)
    {
        if (size == 1)
        {
            return;
        }
        else if (size == 2)
        {
            if (a[0] > a[1])
            {
                value = a[1];
                pos = 1;
                return;
            }
            else if (a[0] < a[1])
            {
                value = a[0];
                pos = 0;
                return;
            }
            else if (a[0] == a[1])
            {
                return;
            }
        }
        else if (size >= 3)
        {
            // This smallArr is to avoid changing mushGhostTransformedArray
            int smallArr[3] = { a[0], a[1], a[2] };
            for (int i = 0; i < 3 - 1; i++)
                for (int j = i + 1; j < 3; j++)
                    if (smallArr[i] > smallArr[j])
                    {
                        int temp = smallArr[i];
                        smallArr[i] = smallArr[j];
                        smallArr[j] = temp;
                    }
            if ((smallArr[0] == smallArr[1]) && (smallArr[1] == smallArr[2]))
                return;
            if (smallArr[1] == smallArr[2])
            {
                value = smallArr[0];
                pos = 0;
                return;
            }
            value = smallArr[1];
            if (smallArr[1] == a[0])
                pos = 0;
            else if (smallArr[1] == a[1])
                pos = 1;
            else if (smallArr[1] == a[2])
                pos = 2;
        }
    }
};

class Hero
{
public:
    const int LEVEL_MAX = 10;
    const int MEDICINE_MAX = 99;
    int maxHP = 0, HP = 0;
    int level = 0, levelBeforeTiny = 0;
    int remedy = 0, maidenkiss = 0, phoenixdown = 0;
    int rescue = -1;
    bool isArthur = false;
    bool isLancelot = false;
    bool MetMerlin = false;
    string pathToKoopa;
    string pack[3];

    void isSpecialState()
    {
        if (maxHP == 999)
        {
            isArthur = true;
        }
        else
        {
            CalcMath math;
            isLancelot = math.isPrimeNum(maxHP);
        }
    }

    void displayStatus()
    {
        cout << "HP=" << HP
            << ", level=" << level
            << ", remedy=" << remedy
            << ", maidenkiss=" << maidenkiss
            << ", phoenixdown=" << phoenixdown
            << ", rescue=" << rescue << endl;
    }

    void readInput(string file_input) // Đọc input đầu vào của file tc1_input
    {
        ifstream f;
        f.open(file_input);
        f >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
        maxHP = HP;
        getline(f, pathToKoopa); // Skip dòng đầu đọc chỉ có khoảng trắng
        getline(f, pathToKoopa);
        string packString;
        getline(f, packString);

        // Loại bỏ escape sequence /r trong chuỗi pathToKoopa
        if (pathToKoopa[pathToKoopa.length() - 1] == '\r')
        {
            pathToKoopa.erase(pathToKoopa.length() - 1, 1);
        }

        bool existMushGhostPack = true;
        bool existAsclepiusPack = true;
        bool existMerlinPack = true;

        // Loại bỏ dấu phẩy trong chuỗi chứa 3 pack
        int n1 = packString.find_first_of(',');
        if (n1 == 0)
        {
            existMushGhostPack = false;
        }
        if (packString[n1+1] == ',')
        {
            existAsclepiusPack = false;
        }
        if (packString[packString.length() - 1] == ',')
        {
            existMerlinPack = false;
        }
        if (n1 >= 0)
        {
            packString.replace(n1, 1, " ");
        }
        n1 = packString.find_first_of(',');
        if (n1 >= 0)
        {
            packString.replace(n1, 1, " ");
        }
        f.close();

        stringstream str(packString);
        if (existMushGhostPack == true)
        {
            str >> pack[0]; //asclepius_pack
        }
        if (existAsclepiusPack == true)
        {
            str >> pack[1]; //merlin_pack
        }
        if (existMerlinPack == true)
        {
            str >> pack[2]; //mush_ghost
        }

    }

    bool isAdventureEnd(stringstream &path)
    {
        bool check = path.eof();
        return check;
    }

    void updateEffect(Monster &mons)
    {
        if (mons.effectLeft > 0)
        {
            if (mons.isShamanEffect == true)
            {
                if (remedy > 0)
                {
                    useRemedy(mons);
                    mons.isShamanEffect = false;
                    return;
                }
                mons.effectLeft--;
                if (mons.effectLeft == 0)
                {
                    if (HP > 0)
                    {
                        setHP(HP * 5);
                    }
                    mons.isShamanEffect = false;
                    return;
                }
            }
			else if (mons.isVajshEffect == true)
			{
				if (maidenkiss > 0)
				{
					useMaidenKiss(mons);
                    mons.isVajshEffect = false;
					return;
				}
				mons.effectLeft--;
				if (mons.effectLeft == 0)
				{
					level = levelBeforeTiny;
                    mons.isVajshEffect = false;
					return;
				}
			}
        }
    }

    void usePhoenixDown(Monster &mons)
    {
        if (phoenixdown > 0)
        {
            phoenixdown--;
            if (mons.effectLeft > 0)
                mons.effectLeft = 0;
            HP = maxHP;
        }
    }

    void useRemedy(Monster &monsEffect)
    {
        remedy--;
        monsEffect.effectLeft = 0;
        setHP(HP * 5);
        monsEffect.isShamanEffect = false;
    }

    void useMaidenKiss(Monster& monsEffect)
    {
        maidenkiss--;
        monsEffect.effectLeft = 0;
        level = levelBeforeTiny;
        monsEffect.isVajshEffect = false;
    }

    // only for private use

    void addMedicine(int &medicineName)
    {
        if (medicineName < MEDICINE_MAX)
        {
            medicineName++;
        }
    }

    void changeHP(int numberOfHPadded)
    {
        if (HP + numberOfHPadded > maxHP)
            HP = maxHP;
        else
            HP += numberOfHPadded;
    }

    void setHP(int numberOfHPset)
    {
        if (numberOfHPset > maxHP)
        {
            HP = maxHP;
        }
        else
            HP = numberOfHPset;
    }

    void addLevel(int levelIncreaseNum)
    {
        if (level + levelIncreaseNum <= 10)
        {
            level += levelIncreaseNum;
        }
        else
        {
            level = LEVEL_MAX;
        }
    }
};

class Asclepius
{
public:
    bool metAsclepius = false;
    void useAsclepiusPack(Hero &hr, Monster &mons)
    {
        int r1, c1;
        ifstream f;
        f.open(hr.pack[1]);
        f >> r1 >> c1;
        int medicine;
        for (int i = 0; i < r1; i++)
        {
            int medPerLine = 0;
            for (int j = 0; j < c1; j++)
            {
                f >> medicine;
                if (medPerLine < 3)
                {
                    switch (medicine)
                    {
                    case 16:
                    {
                        hr.addMedicine(hr.remedy);
                        if (mons.effectLeft > 0)
                        {
                            hr.useRemedy(mons);
                        }
                        medPerLine++;
                        break;
                    }
                    case 17:
                    {
                        hr.addMedicine(hr.maidenkiss);
                        if (mons.effectLeft > 0)
                        {
                            hr.useMaidenKiss(mons);
                        }
                        medPerLine++;
                        break;
                    }
                    case 18:
                    {
                        hr.addMedicine(hr.phoenixdown);
                        medPerLine++;
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
        }
    }
};

class Merlin
{
public:
    bool metMerlin = false;
    string merlinUpper = "Merlin";
    string merlinLower = "merlin";
    int addHPMerlinPack(string str)
    {
        if ((str.find(merlinUpper) >= 0) && (str.find(merlinUpper) < str.size()) ||
            (str.find(merlinLower) >= 0) && (str.find(merlinLower) < str.size()))
        {
            return 3;
        }
        else
        {
            char merlinCharLower[] = { 'm', 'e', 'r', 'l', 'i', 'n' };
            char merlinCharUpper[] = { 'M', 'E', 'R', 'L', 'I', 'N' };
            int count = 0;
            for (int i = 0; i < 6; i++)
            {
                if ((str.find(merlinCharLower[i]) >= 0) && (str.find(merlinCharLower[i]) < str.size()) ||
                    (str.find(merlinCharUpper[i]) >= 0) && (str.find(merlinCharUpper[i]) < str.size()))
                {
                    count++;
                }
            }
            if (count == 6)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
    }

    void useMerlinPack(Hero& hr, Monster& mons)
    {
        ifstream f;
        f.open(hr.pack[2]);
        int n9;
        f >> n9;
        int totalHPAdded = 0;
        string merlinItem;
        for (int i = 0; i < n9; i++)
        {
            f >> merlinItem;
            totalHPAdded += addHPMerlinPack(merlinItem);
        }
        hr.changeHP(totalHPAdded);
        metMerlin = true;
    }
};

class MushGhost
{
public:
    int amountOfMustGhost = 0;
    int mushGhostOriginalArray[100] = { 0 };
    int mushGhostTransformedArray[100] = { 0 };
    void readListOfMushGhost(Hero hr)
    {
        ifstream f;
        f.open(hr.pack[0]);
        f >> amountOfMustGhost;
        string mushGhostString = "";
        getline(f, mushGhostString); // Skip qua dòng getline đầu tiên
        getline(f, mushGhostString);
        f.close();

        int pos = mushGhostString.find_first_of(',');
        while (pos >= 0)
        {
            mushGhostString.replace(pos, 1, " ");
            pos = mushGhostString.find_first_of(',');
        }

        stringstream readMush(mushGhostString);
        for (int i = 0; i < amountOfMustGhost; i++)
        {
            readMush >> mushGhostOriginalArray[i];
            mushGhostTransformedArray[i] = mushGhostOriginalArray[i];
        }
        CalcMath math;
        math.transformArrayMush3and4(mushGhostTransformedArray, amountOfMustGhost);
    }

    void getMush_1(Hero& hr, Monster& mons, CalcMath math)
    {
        int maxi = 0, mini = 0;
        math.findLastPositionMaxMin(mushGhostOriginalArray, maxi, mini, amountOfMustGhost);
        int damage = (maxi + mini);
        hr.changeHP(-damage);
    }

    void getMush_2(Hero& hr, Monster& mons, CalcMath math)
    {
        int mtx = -2, mti = -3;
        math.findMountainPeak(mushGhostOriginalArray, mti, mtx, amountOfMustGhost);
        int damage = (mtx + mti);
        hr.changeHP(-damage);
    }

    void getMush_3(Hero& hr, Monster& mons, CalcMath math)
    {
        int maxi2 = 0, mini2 = 0;
        math.findFirstPositionMaxMin(mushGhostTransformedArray, maxi2, mini2, amountOfMustGhost);
        int damage = (maxi2 + mini2);
        hr.changeHP(-damage);
    }

    void getMush_4(Hero& hr, Monster& mons, CalcMath math)
    {
        int max2_3x = -5, max2_3i = -7;
        math.findSecondLargestNum(mushGhostTransformedArray, max2_3x, max2_3i, amountOfMustGhost);
        int damage = (max2_3x + max2_3i);
        hr.changeHP(-damage);
    }
};

class EventInKoopa
{
public:
    int eventCode = 0;
    int numOfEvent = 0;
    void Win_0(Hero &hr)
    {
        hr.rescue = 1;
    }

    void fightingMonster_1to5(Hero &hr, Monster mons, int monsterNum, int eventNum)
    {
        mons.calculateLevelO(eventNum);
        if (hr.level > mons.levelO)
        {
            hr.addLevel(1);
        }
        else if (hr.level < mons.levelO)
        {
            mons.calculateBaseDamage(eventNum, monsterNum);
            hr.changeHP(-mons.damage);
            if (hr.HP <= 0)
            {
                hr.usePhoenixDown(mons);
            }
            if (hr.HP <= 0)
            {
                hr.rescue = 0;
            }
        }
    }

    void fightingShaman_6(Hero &hr, Monster &shaman, int eventNum)
    {
        if (shaman.effectLeft == 0)
        {
            shaman.calculateLevelO(eventNum);
            if (hr.level > shaman.levelO)
            {
                hr.addLevel(2);
            }
            else if (hr.level < shaman.levelO)
            {
                shaman.applyShamanEffect(hr.HP);
                if (hr.remedy > 0 && shaman.isShamanEffect == true)
                {
                    hr.useRemedy(shaman);
                    hr.setHP(hr.maxHP); // nếu vừa bị dính hiệu ứng mà có thuốc thì HP giữ nguyên
                }
            }
        }
    }

    void fightingVajsh_7(Hero &hr, Monster &vajsh, int eventNum)
    {
        if (vajsh.effectLeft == 0)
        {
            vajsh.calculateLevelO(eventNum);
            if (hr.level > vajsh.levelO)
            {
                hr.addLevel(2);
            }
            else if (hr.level < vajsh.levelO)
            {
                vajsh.applyVajshEffect(hr.level, hr.levelBeforeTiny);
                if (hr.maidenkiss > 0 && vajsh.isVajshEffect == true)
                {
                    hr.useMaidenKiss(vajsh);
                }
            }
        }
    }

    void getMushMario_11(Hero &hr, CalcMath math)
    {
        int n1 = ((hr.level + hr.phoenixdown) % 5 + 1) * 3;
        int s1 = math.SumOfSomeLargestOddNums(n1);
        int HP_added = s1 % 100;
        hr.changeHP(HP_added);
        int newHP = math.findUpperNearestPrimeNum(hr.HP);
        hr.setHP(newHP);
    }

    void getMushFibo_12(Hero &hr, CalcMath math)
    {
        int newHP = math.findLowerNearestFibonacci(hr.HP);
        hr.setHP(newHP);
    }

    void getMushGhost_13(Hero &hr, Monster &mons, CalcMath math, int listOfMushGhost)
    {
        int amountOfMush = math.countNumDigit(listOfMushGhost) - 2;
        //int power = pow(10, amountOfMush);
        int power = 1;
        for (int i = 0; i < amountOfMush; i++)
        {
            power = power * 10;
        }
        MushGhost mushghost;
        mushghost.readListOfMushGhost(hr);
        listOfMushGhost = listOfMushGhost % power;
        int currentMushGhost = 0;
        while (listOfMushGhost != 0)
        {
            currentMushGhost = listOfMushGhost / (power / 10);
            switch (currentMushGhost)
            {
            case 1: 
                mushghost.getMush_1(hr, mons, math);
                break;
            case 2: 
                mushghost.getMush_2(hr, mons, math);
                break;
            case 3: 
                mushghost.getMush_3(hr, mons, math);
                break;
            case 4: 
                mushghost.getMush_4(hr, mons, math);
                break;
            default:
                break;
            }
            listOfMushGhost = listOfMushGhost % (power / 10);
            power = power / 10;
            if (hr.HP <= 0)
            {
                hr.usePhoenixDown(mons);
            }
            if (hr.HP <= 0)
            {
                hr.rescue = 0;
                break;
            }
        }
    }

    void getRemedy_15(Hero &hr)
    {
        hr.addMedicine(hr.remedy);
    }

    void getMaidenKiss_16(Hero &hr)
    {
        hr.addMedicine(hr.maidenkiss);
    }

    void getPhoenixDown_17(Hero &hr)
    {
        hr.addMedicine(hr.phoenixdown);
    }

    void getAsclepiusPack_19(Hero& hr, Asclepius &asclepiusGod, Monster &mons)
    {
        asclepiusGod.metAsclepius = true;
        asclepiusGod.useAsclepiusPack(hr, mons);
    }

    void fightBowser_99(Hero& hr)
    {
        if (hr.isArthur == true || (hr.isLancelot == true && hr.level >= 8) )
        {
            hr.addLevel(10);
        }
        else
        {
            hr.rescue = 0;
        }
    }

    void getMerlinPack(Hero &hr ,Merlin &merlin, Monster& mons)
    {
        if (merlin.metMerlin == false)
        {
            merlin.useMerlinPack(hr, mons);
        }
    }
};


// Hàm xử lý hành trình tới Koopa
void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    Hero myHero;
    myHero.readInput(file_input);

    EventInKoopa heroEvent;
    Monster monster;
    CalcMath mathProcess;
    stringstream loadPathToKoopa(myHero.pathToKoopa);
    Asclepius asclepiusGod;
    Merlin merlinGod;
    
    // Kiểm tra trạng thái đặc biệt của hiệp sĩ
    myHero.isSpecialState();

    // vòng lặp xử lý từng event
    while (!loadPathToKoopa.eof())
    {
        loadPathToKoopa >> heroEvent.eventCode;
        heroEvent.numOfEvent++;
        if (heroEvent.eventCode == 0)
        {
            heroEvent.Win_0(myHero);
        }
        else if (heroEvent.eventCode >= 1 && heroEvent.eventCode <= 5)
        {
            if (myHero.isArthur == true || myHero.isLancelot == true)
                myHero.addLevel(1);
            else
                heroEvent.fightingMonster_1to5(myHero, monster, heroEvent.eventCode, heroEvent.numOfEvent);
        }
        else if (heroEvent.eventCode == 6)
        {
            if (myHero.isArthur == true || myHero.isLancelot == true)
                myHero.addLevel(2);
            else
                heroEvent.fightingShaman_6(myHero, monster, heroEvent.numOfEvent);
        }
        else if (heroEvent.eventCode == 7)
        {
            if (myHero.isArthur == true || myHero.isLancelot == true)
                myHero.addLevel(2);
            else
                heroEvent.fightingVajsh_7(myHero, monster, heroEvent.numOfEvent);
        }
        else if (heroEvent.eventCode == 11)
        {
            heroEvent.getMushMario_11(myHero, mathProcess);
        }
        else if (heroEvent.eventCode == 12)
        {
            heroEvent.getMushFibo_12(myHero, mathProcess);
        }
        else if (mathProcess.findFirstTwoDigitOfNum(heroEvent.eventCode) == 13)
        {
            heroEvent.getMushGhost_13(myHero, monster, mathProcess, heroEvent.eventCode);
        }
        else if (heroEvent.eventCode == 15)
        {
            heroEvent.getRemedy_15(myHero);
        }
        else if (heroEvent.eventCode == 16)
        {
            heroEvent.getMaidenKiss_16(myHero);
        }
        else if (heroEvent.eventCode == 17)
        {
            heroEvent.getPhoenixDown_17(myHero);
        }
        else if (heroEvent.eventCode == 18)
        {
            heroEvent.getMerlinPack(myHero, merlinGod, monster);
        }
        else if (heroEvent.eventCode == 19 && (asclepiusGod.metAsclepius == false))
        {
            heroEvent.getAsclepiusPack_19(myHero, asclepiusGod, monster);
        }
        else if (heroEvent.eventCode == 99 && (merlinGod.metMerlin == false))
        {
            heroEvent.fightBowser_99(myHero);
        }

        // Kiểm tra và show trạng thái hiệp sĩ trước khi kết thúc
        if ((myHero.isAdventureEnd(loadPathToKoopa) == true) && (myHero.rescue != 0))
        {
            myHero.rescue = 1;
        }
        myHero.updateEffect(monster);
        myHero.displayStatus();
        if (myHero.rescue == 1 || myHero.rescue == 0)
        {
            break;
        }
    }
}

// ĐẾN ĐÂY LÀ HẾT FILE knight.cpp