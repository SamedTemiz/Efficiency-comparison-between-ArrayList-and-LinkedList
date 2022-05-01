#include <iostream>
#include <conio.h>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node
{
	int deger;					//düðümün sayýsal deðeri
	Node* sonraki;				//sonraki düðüme iþaretçi
};

struct LinkedList
{
	Node* bas;					//listenin baþlangýç adresini tutar
	void olustur();				//baþlangýç için gereken tanýmlarý içerir
	void ekle(int, int);		//deðer ve sýra numarasý alarak ekleme yapar
	void guncelle(int, int);	//deðer ve sýra numarasý alarak günceller
	void sil(int);				//sýra numarasý alarak silme yapar
	void yazdir();				//liste içeriðini ekrana yazar
	void bosalt();				//listenin bellek alanlarýný iade eder
	int sayac;					//liste kaç eleman olduðunu tutar
};

struct ArrayList
{
	int* bas;					//dizinin baþlangýç adresini tutar
	void olustur();				//baþlangýç için gereken tanýmlarý içerir
	void ekle(int, int);		//deðer ve sýra numarasý alarak ekleme yapar
	void guncelle(int, int);	//deðer ve sýra numarasý alarak güncelleme yapar
	void sil(int);				//sýra numarasý alarak silme yapar
	void yazdir();				//liste içeriðini ekrana yazar
	void bosalt();				//listenin bellek alanlarýný iade eder
	int sayac;					//liste'nin kaç eleman olduðunu tutar
};

/*
Liste soyut veri tipini iki farklý þekilde gerçekledikten sonra içerisine sýrasýyla 100, 1000 ve 10000 veri
ekleyiniz. (Ekleme iþlemlerini her iki yapý için ayrý ayrý tekrarlayýnýz.) Daha sonra, veri kümesinin ortasýna
baþýna ve sonuna ekleme yaparak her iki gerçeklemede elde ettiðiniz performans deðiþimini
raporlayýnýz. (Performans farký gözlemlemediðiniz takdirde veri kümesini daha fazla eleman içerecek
þekilde oluþturabilirsiniz.) Bu iþlemleri silme ve güncelleme operasyonlarý için tekrarlayýnýz. Program
sonlanmadan önce sistemden aldýðýnýz bellek gözlerini iade ediniz.
*/

int main()
{
start:
	int adet; //Örnek 10-100-1000 vb.
	cout << "Ornek -> 100 -> 1000 -> 10000" << endl;
	cout << "Liste boyutunu giriniz : ";
	cin >> adet;
	srand(time(0));
	int sayi = rand() % (adet + 1); //Rastgele sayý üretiyoruz.

	LinkedList* liste = new LinkedList();
	ArrayList* dizi = new ArrayList();
	dizi->sayac = adet;
	// 0'dan -> adet sayisina
	liste->olustur();	//Liste oluþturuluyor
	dizi->olustur();	//Dizi için pointer belirtiyoruz

	cout << endl << adet << " elemanli bir listede; " << endl;
	cout << endl;
	//Baðlantýlý listeyi istenilen adet sayýsýna kadar dolduruyoruz
	auto liste_s = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < adet; i++)
	{
		liste->ekle(i, i); //Sýfýrdan verilen adete kadar olan sayýlarý sýrasýyla listeye ekliyoruz
	}
	auto liste_e = std::chrono::high_resolution_clock::now();
	auto liste_r = std::chrono::duration_cast<std::chrono::nanoseconds>(liste_e - liste_s);
	cout << "Baglantili listeyi olusturma suresi => " << liste_r.count() << " nano-saniye" << endl;
	//Dizi listeyi istenilen adet sayýsýna kadar dolduruyoruz
	auto dizi_s = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < adet; i++)
	{
		dizi->ekle(i, i);
	}
	auto dizi_e = std::chrono::high_resolution_clock::now();
	auto dizi_r = std::chrono::duration_cast<std::chrono::nanoseconds>(dizi_e - dizi_s);
	cout << "Dizi listeyi olusturma suresi => " << dizi_r.count() << " nano-saniye" << endl;
	cout << endl;

	//Ekleme için süre takibi---------------------------------------------------------------------------------------------
	auto liste_s1 = std::chrono::high_resolution_clock::now();
	liste->ekle(555, sayi); // (0: Listenin baþý), (sayi: Rastgele bir düðüm sonrasý), (10000: Listenin sonu)
	auto liste_e1 = std::chrono::high_resolution_clock::now();
	auto liste_r1 = std::chrono::duration_cast<std::chrono::nanoseconds>(liste_e1 - liste_s1);
	cout << "Baglantili liste ile gerceklemede EKLEME suresi => " << liste_r1.count() << " nano-saniye" << endl;

	auto dizi_s1 = std::chrono::high_resolution_clock::now();
	dizi->ekle(555, sayi); // (0: Listenin baþý), (sayi: Rastgele bir düðüm sonrasý), (10000: Listenin sonu)
	auto dizi_e1 = std::chrono::high_resolution_clock::now();
	auto dizi_r1 = std::chrono::duration_cast<std::chrono::nanoseconds>(dizi_e1 - dizi_s1);
	cout << "Dizi liste ile gerceklemede EKLEME suresi => " << dizi_r1.count() << " nano-saniye" << endl;
	cout << endl;

	//Güncelleme için süre takibi------------------------------------------------------------------------------------------
	auto liste_s2 = std::chrono::high_resolution_clock::now();
	liste->guncelle(888, sayi); // Rastgele bir konumdaki(sayi) deðeri 888 ile güncelliyoruz
	auto liste_e2 = std::chrono::high_resolution_clock::now();
	auto liste_r2 = std::chrono::duration_cast<std::chrono::nanoseconds>(liste_e2 - liste_s2);
	cout << "Baglantili liste ile gerceklemede node GUNCELLEME suresi => " << liste_r2.count() << " nano-saniye" << endl;

	auto dizi_s2 = std::chrono::high_resolution_clock::now();
	dizi->guncelle(888, sayi); // Rastgele bir konumdaki(sayi) deðeri 888 ile güncelliyoruz
	auto dizi_e2 = std::chrono::high_resolution_clock::now();
	auto dizi_r2 = std::chrono::duration_cast<std::chrono::nanoseconds>(dizi_e2 - dizi_s2);
	cout << "Dizi liste ile gerceklemede GUNCELLEME suresi => " << dizi_r2.count() << " nano-saniye" << endl;
	cout << endl;

	//Sil için süre takibi--------------------------------------------------------------------------------------------------
	auto liste_s3 = std::chrono::high_resolution_clock::now();
	liste->sil(6); // Ýstenilen konumdaki(6) deðeri siliyoruz
	auto liste_e3 = std::chrono::high_resolution_clock::now();
	auto liste_r3 = std::chrono::duration_cast<std::chrono::nanoseconds>(liste_e3 - liste_s3);
	cout << "Baglantili liste ile gerceklemede node SILME suresi => " << liste_r3.count() << " nano-saniye" << endl;

	auto dizi_s3 = std::chrono::high_resolution_clock::now();
	dizi->sil(6);  // Ýstenilen konumdaki(6) deðeri siliyoruz
	auto dizi_e3 = std::chrono::high_resolution_clock::now();
	auto dizi_r3 = std::chrono::duration_cast<std::chrono::nanoseconds>(dizi_e3 - dizi_s3);
	cout << "Dizi liste ile gerceklemede SILME suresi => " << dizi_r3.count() << " nano-saniye" << endl;
	cout << endl;

	//Temizleme için süre takibi--------------------------------------------------------------------------------------------
	auto liste_s4 = std::chrono::high_resolution_clock::now();
	liste->bosalt(); // Listeyi boþaltýyoruz
	auto liste_e4 = std::chrono::high_resolution_clock::now();
	auto liste_r4 = std::chrono::duration_cast<std::chrono::nanoseconds>(liste_e4 - liste_s4);
	cout << "Baglantili liste ile gerceklemede BAGLANTILI LISTE TEMIZLEME suresi => " << liste_r4.count() << " nano-saniye" << endl;
	auto dizi_s4 = std::chrono::high_resolution_clock::now();
	dizi->bosalt();  // Diziyi boþaltýyoruz
	auto dizi_e4 = std::chrono::high_resolution_clock::now();
	auto dizi_r4 = std::chrono::duration_cast<std::chrono::nanoseconds>(dizi_e4 - dizi_s4);
	cout << "Dizi liste ile gerceklemede DIZI TEMIZLEME suresi => " << dizi_r4.count() << " nano-saniye" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << endl;
	//-------------------SON----------------------
soru:
	cout << "Ekrani temizlemek ve yeniden baslamak icin 1'e basin..." << endl;
	int sonuc;
	cin >> sonuc;
	if (sonuc == 1)
	{
		system("CLS");
		goto start;
	}
	else
	{
		goto soru;
	}
}

void ArrayList::olustur()
{
	bas = NULL; //iþaretcimiz baþlangýçta NULL
	if (sayac != 0) //dizi boyutu 0 deðilse
	{
		bas = new int[sayac];	//Liste oluþtu, bas degerine dizinin baslangic adresi verildi
	}
	else
	{
		cout << "Dizi olusturulamadi, HATA!";
		return;
	}
}
void LinkedList::olustur()
{
	bas = NULL;	 //Liste oluþtu, ilk eleman NULL olarak atandý.
	sayac = 0;
}

void ArrayList::ekle(int data, int n)
{
	if (bas != NULL)						//liste oluþmuþ ise
	{
		int* list;  
		list = bas;							//baþlangýc adresimizi kaybetmemek için yeni iþaretçi kullanýyoruz
		int i = 0;
		for (i = sayac; i > n; i--)			//Ekleme yapýnca sondaki elemaný silecek þekilde kaydýrýyoruz
		{
			*(list + i) = *(list + i - 1);  //iþaretçi ile istenen yere kadar ilerliyoruz
		}
		*(list + i) = data;					//iþaretçinin gösterdiði adrese girilen veriyi ekliyoruz
		list = bas;							//iþaretçimiz dizinin baþýna dönüyor
	}
	else
	{
		cout << endl << "Henuz dizi olusturmadiniz!";
		return;
	}
}
void LinkedList::ekle(int data, int n)
{
	Node* temp1 = new Node();		//yeni düðüm oluþturduk
	temp1->deger = data;			//oluþturduðumuz düðümün deðerini verdik
	temp1->sonraki = NULL;			//sonraki düðüm adresi henüz yok
	if (n == 0)						//Listenin baþý belirtiliyor ise
	{
		temp1->sonraki = bas;		//baþa eklemek için baþtaki düðümün adresini sonraki olarak alýyoruz
		bas = temp1;
		return;
	}
	Node* temp2 = bas;				//yeni düðüm oluþturduk
	for (int i = 0; i < n - 1; i++) //verilen adet kadar düðümü ilerletiyoruz
	{
		temp2 = temp2->sonraki;		//adet sayýsý bitene kadar düðüm adresleri sonraki ye ekleniyor
	}
	temp1->sonraki = temp2->sonraki;//temp1 istenilen sýraya sokuluyor
	temp2->sonraki = temp1;			//temp1 araya giriyor
}

void ArrayList::guncelle(int data, int n)
{
	if (bas != NULL)
	{
		int* list;					//yeni iþaretçi oluþturdum
		list = bas;					//yeni iþaretçiyi dizinin baþýna eþitledim
		for (int i = 0; i < n; i++)
		{
			list++;					//iþaretçi ile istenen yere kadar ilerliyoruz
		}
		*list = data;				//iþaretçinin gösterdiði adrese girilen veriyi güncelliyoruz
		list = bas;					//iþaretçimiz dizinin baþýna dönüyor
	}
	else
	{
		cout << endl << "Henuz dizi olusturmadiniz!";
		return;
	}
}
void LinkedList::guncelle(int data, int n)
{
	if (bas == NULL)
	{
		cout << "Liste bos!";
		return;
	}
	Node* tara;
	tara = bas;
	for (int i = 0; i < n; i++)		// istenilen sýradaki düðüme kadar çalýþtýrýyoruz
	{
		if(tara->sonraki != NULL)
			tara = tara->sonraki;
	}
	tara->deger = data;				//mevcut düðümdeki deðeri istenilen ile deðiþtiriyoruz
}

void ArrayList::sil(int n)
{
	if (bas != NULL)									//liste oluþmuþ ise
	{
		if (n < sayac)
		{
			int* list;									//yeni iþaretçi oluþturduk
			list = bas;									//yeni iþaretçiyi dizinin baþýna eþitledik
			int konum = 0;
			for (int i = 0; i < n - 1; i++)
			{
				list++;									//iþaretçi ile istenen indise kadar ilerliyoruz
				konum++;
			}
			for (int i = 0; i < (sayac - konum); i++)	//silinen indis deðeri için listeyi sola kaydýrýyoruz
			{
				*list = *(list + 1);
				list++;
			}
			//cout << "Silme islemi basarili, dizi icerigi kaydiriliyor.." << endl;
		}
		else
		{
			cout << "Lutfen gecerli indis numarasi giriniz!"<< endl;
			return;
		}
	}
	else
	{
		cout << endl << "Henuz liste olusturmadiniz!";//list oluþmamýþsa uyarý metni
		return;
	}
}
void LinkedList::sil(int n)
{
	if (bas == NULL)
	{
		cout << "Liste bos!";
		return;
	}
	Node* temp1 = bas;
	for (int i = 0; i < n - 2; i++)		//istenilen düðüme kadar çalýþtýrýyoruz
	{
		temp1 = temp1->sonraki;
	}
	Node* temp2 = temp1->sonraki;
	temp1->sonraki = temp2->sonraki;	// önceki düðüm ile sonraki düðümü baðlýyoruz
	free(temp2);						//istediðimiz düðümü siliyoruz
}

void ArrayList::yazdir()
{
	int* oku;							//yeni iþaretçi oluþturdum
	oku = bas;							//dizinin baþlangýç adresine eþitledim
	if (oku != NULL)
	{
		for (int i = 0; i < sayac; i++)
		{
			cout << *oku << " ";		//adresteki deðeri ekrana yazýyor
			oku++;						//bir sonraki adrese gidiyor +4 byte
		}
		oku = bas;						//yazma iþlemi bittikten sonra baþlangýça geri döndük
	}
	else
	{
		cout << "Dizi YOK!";
		return;
	}
}
void LinkedList::yazdir()
{
	Node* tara;
	tara = bas;
	if (!tara)
	{
		cout << "Liste bos!" << endl;
		return;
	}
	while (tara)
	{
		cout << tara->deger << " ";
		tara = tara->sonraki;
	}
	cout << endl;
}

void ArrayList::bosalt()
{	
	if (bas != NULL) //liste dolu ise
	{
		bas = new int[sayac];
		delete[] bas;
		bas = NULL; //baþlangýç adresini siliyoruz
		//cout << endl <<"Dizi TEMIZLENDI" << endl;
		return;
	}
	else
	{
		cout << "HATA!";
		return;
	}

}
void LinkedList::bosalt()
{
	Node* temp = bas;
	while (temp != NULL)
	{
		temp = temp->sonraki;
		delete bas;
		bas = temp;
	}
	//cout << "Liste temizlendi!";
	return;
}
