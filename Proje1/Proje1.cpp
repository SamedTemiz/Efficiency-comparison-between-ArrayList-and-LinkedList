#include <iostream>
#include <conio.h>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node
{
	int deger;					//d���m�n say�sal de�eri
	Node* sonraki;				//sonraki d���me i�aret�i
};

struct LinkedList
{
	Node* bas;					//listenin ba�lang�� adresini tutar
	void olustur();				//ba�lang�� i�in gereken tan�mlar� i�erir
	void ekle(int, int);		//de�er ve s�ra numaras� alarak ekleme yapar
	void guncelle(int, int);	//de�er ve s�ra numaras� alarak g�nceller
	void sil(int);				//s�ra numaras� alarak silme yapar
	void yazdir();				//liste i�eri�ini ekrana yazar
	void bosalt();				//listenin bellek alanlar�n� iade eder
	int sayac;					//liste ka� eleman oldu�unu tutar
};

struct ArrayList
{
	int* bas;					//dizinin ba�lang�� adresini tutar
	void olustur();				//ba�lang�� i�in gereken tan�mlar� i�erir
	void ekle(int, int);		//de�er ve s�ra numaras� alarak ekleme yapar
	void guncelle(int, int);	//de�er ve s�ra numaras� alarak g�ncelleme yapar
	void sil(int);				//s�ra numaras� alarak silme yapar
	void yazdir();				//liste i�eri�ini ekrana yazar
	void bosalt();				//listenin bellek alanlar�n� iade eder
	int sayac;					//liste'nin ka� eleman oldu�unu tutar
};

/*
Liste soyut veri tipini iki farkl� �ekilde ger�ekledikten sonra i�erisine s�ras�yla 100, 1000 ve 10000 veri
ekleyiniz. (Ekleme i�lemlerini her iki yap� i�in ayr� ayr� tekrarlay�n�z.) Daha sonra, veri k�mesinin ortas�na
ba��na ve sonuna ekleme yaparak her iki ger�eklemede elde etti�iniz performans de�i�imini
raporlay�n�z. (Performans fark� g�zlemlemedi�iniz takdirde veri k�mesini daha fazla eleman i�erecek
�ekilde olu�turabilirsiniz.) Bu i�lemleri silme ve g�ncelleme operasyonlar� i�in tekrarlay�n�z. Program
sonlanmadan �nce sistemden ald���n�z bellek g�zlerini iade ediniz.
*/

int main()
{
start:
	int adet; //�rnek 10-100-1000 vb.
	cout << "Ornek -> 100 -> 1000 -> 10000" << endl;
	cout << "Liste boyutunu giriniz : ";
	cin >> adet;
	srand(time(0));
	int sayi = rand() % (adet + 1); //Rastgele say� �retiyoruz.

	LinkedList* liste = new LinkedList();
	ArrayList* dizi = new ArrayList();
	dizi->sayac = adet;
	// 0'dan -> adet sayisina
	liste->olustur();	//Liste olu�turuluyor
	dizi->olustur();	//Dizi i�in pointer belirtiyoruz

	cout << endl << adet << " elemanli bir listede; " << endl;
	cout << endl;
	//Ba�lant�l� listeyi istenilen adet say�s�na kadar dolduruyoruz
	auto liste_s = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < adet; i++)
	{
		liste->ekle(i, i); //S�f�rdan verilen adete kadar olan say�lar� s�ras�yla listeye ekliyoruz
	}
	auto liste_e = std::chrono::high_resolution_clock::now();
	auto liste_r = std::chrono::duration_cast<std::chrono::nanoseconds>(liste_e - liste_s);
	cout << "Baglantili listeyi olusturma suresi => " << liste_r.count() << " nano-saniye" << endl;
	//Dizi listeyi istenilen adet say�s�na kadar dolduruyoruz
	auto dizi_s = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < adet; i++)
	{
		dizi->ekle(i, i);
	}
	auto dizi_e = std::chrono::high_resolution_clock::now();
	auto dizi_r = std::chrono::duration_cast<std::chrono::nanoseconds>(dizi_e - dizi_s);
	cout << "Dizi listeyi olusturma suresi => " << dizi_r.count() << " nano-saniye" << endl;
	cout << endl;

	//Ekleme i�in s�re takibi---------------------------------------------------------------------------------------------
	auto liste_s1 = std::chrono::high_resolution_clock::now();
	liste->ekle(555, sayi); // (0: Listenin ba��), (sayi: Rastgele bir d���m sonras�), (10000: Listenin sonu)
	auto liste_e1 = std::chrono::high_resolution_clock::now();
	auto liste_r1 = std::chrono::duration_cast<std::chrono::nanoseconds>(liste_e1 - liste_s1);
	cout << "Baglantili liste ile gerceklemede EKLEME suresi => " << liste_r1.count() << " nano-saniye" << endl;

	auto dizi_s1 = std::chrono::high_resolution_clock::now();
	dizi->ekle(555, sayi); // (0: Listenin ba��), (sayi: Rastgele bir d���m sonras�), (10000: Listenin sonu)
	auto dizi_e1 = std::chrono::high_resolution_clock::now();
	auto dizi_r1 = std::chrono::duration_cast<std::chrono::nanoseconds>(dizi_e1 - dizi_s1);
	cout << "Dizi liste ile gerceklemede EKLEME suresi => " << dizi_r1.count() << " nano-saniye" << endl;
	cout << endl;

	//G�ncelleme i�in s�re takibi------------------------------------------------------------------------------------------
	auto liste_s2 = std::chrono::high_resolution_clock::now();
	liste->guncelle(888, sayi); // Rastgele bir konumdaki(sayi) de�eri 888 ile g�ncelliyoruz
	auto liste_e2 = std::chrono::high_resolution_clock::now();
	auto liste_r2 = std::chrono::duration_cast<std::chrono::nanoseconds>(liste_e2 - liste_s2);
	cout << "Baglantili liste ile gerceklemede node GUNCELLEME suresi => " << liste_r2.count() << " nano-saniye" << endl;

	auto dizi_s2 = std::chrono::high_resolution_clock::now();
	dizi->guncelle(888, sayi); // Rastgele bir konumdaki(sayi) de�eri 888 ile g�ncelliyoruz
	auto dizi_e2 = std::chrono::high_resolution_clock::now();
	auto dizi_r2 = std::chrono::duration_cast<std::chrono::nanoseconds>(dizi_e2 - dizi_s2);
	cout << "Dizi liste ile gerceklemede GUNCELLEME suresi => " << dizi_r2.count() << " nano-saniye" << endl;
	cout << endl;

	//Sil i�in s�re takibi--------------------------------------------------------------------------------------------------
	auto liste_s3 = std::chrono::high_resolution_clock::now();
	liste->sil(6); // �stenilen konumdaki(6) de�eri siliyoruz
	auto liste_e3 = std::chrono::high_resolution_clock::now();
	auto liste_r3 = std::chrono::duration_cast<std::chrono::nanoseconds>(liste_e3 - liste_s3);
	cout << "Baglantili liste ile gerceklemede node SILME suresi => " << liste_r3.count() << " nano-saniye" << endl;

	auto dizi_s3 = std::chrono::high_resolution_clock::now();
	dizi->sil(6);  // �stenilen konumdaki(6) de�eri siliyoruz
	auto dizi_e3 = std::chrono::high_resolution_clock::now();
	auto dizi_r3 = std::chrono::duration_cast<std::chrono::nanoseconds>(dizi_e3 - dizi_s3);
	cout << "Dizi liste ile gerceklemede SILME suresi => " << dizi_r3.count() << " nano-saniye" << endl;
	cout << endl;

	//Temizleme i�in s�re takibi--------------------------------------------------------------------------------------------
	auto liste_s4 = std::chrono::high_resolution_clock::now();
	liste->bosalt(); // Listeyi bo�alt�yoruz
	auto liste_e4 = std::chrono::high_resolution_clock::now();
	auto liste_r4 = std::chrono::duration_cast<std::chrono::nanoseconds>(liste_e4 - liste_s4);
	cout << "Baglantili liste ile gerceklemede BAGLANTILI LISTE TEMIZLEME suresi => " << liste_r4.count() << " nano-saniye" << endl;
	auto dizi_s4 = std::chrono::high_resolution_clock::now();
	dizi->bosalt();  // Diziyi bo�alt�yoruz
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
	bas = NULL; //i�aretcimiz ba�lang��ta NULL
	if (sayac != 0) //dizi boyutu 0 de�ilse
	{
		bas = new int[sayac];	//Liste olu�tu, bas degerine dizinin baslangic adresi verildi
	}
	else
	{
		cout << "Dizi olusturulamadi, HATA!";
		return;
	}
}
void LinkedList::olustur()
{
	bas = NULL;	 //Liste olu�tu, ilk eleman NULL olarak atand�.
	sayac = 0;
}

void ArrayList::ekle(int data, int n)
{
	if (bas != NULL)						//liste olu�mu� ise
	{
		int* list;  
		list = bas;							//ba�lang�c adresimizi kaybetmemek i�in yeni i�aret�i kullan�yoruz
		int i = 0;
		for (i = sayac; i > n; i--)			//Ekleme yap�nca sondaki eleman� silecek �ekilde kayd�r�yoruz
		{
			*(list + i) = *(list + i - 1);  //i�aret�i ile istenen yere kadar ilerliyoruz
		}
		*(list + i) = data;					//i�aret�inin g�sterdi�i adrese girilen veriyi ekliyoruz
		list = bas;							//i�aret�imiz dizinin ba��na d�n�yor
	}
	else
	{
		cout << endl << "Henuz dizi olusturmadiniz!";
		return;
	}
}
void LinkedList::ekle(int data, int n)
{
	Node* temp1 = new Node();		//yeni d���m olu�turduk
	temp1->deger = data;			//olu�turdu�umuz d���m�n de�erini verdik
	temp1->sonraki = NULL;			//sonraki d���m adresi hen�z yok
	if (n == 0)						//Listenin ba�� belirtiliyor ise
	{
		temp1->sonraki = bas;		//ba�a eklemek i�in ba�taki d���m�n adresini sonraki olarak al�yoruz
		bas = temp1;
		return;
	}
	Node* temp2 = bas;				//yeni d���m olu�turduk
	for (int i = 0; i < n - 1; i++) //verilen adet kadar d���m� ilerletiyoruz
	{
		temp2 = temp2->sonraki;		//adet say�s� bitene kadar d���m adresleri sonraki ye ekleniyor
	}
	temp1->sonraki = temp2->sonraki;//temp1 istenilen s�raya sokuluyor
	temp2->sonraki = temp1;			//temp1 araya giriyor
}

void ArrayList::guncelle(int data, int n)
{
	if (bas != NULL)
	{
		int* list;					//yeni i�aret�i olu�turdum
		list = bas;					//yeni i�aret�iyi dizinin ba��na e�itledim
		for (int i = 0; i < n; i++)
		{
			list++;					//i�aret�i ile istenen yere kadar ilerliyoruz
		}
		*list = data;				//i�aret�inin g�sterdi�i adrese girilen veriyi g�ncelliyoruz
		list = bas;					//i�aret�imiz dizinin ba��na d�n�yor
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
	for (int i = 0; i < n; i++)		// istenilen s�radaki d���me kadar �al��t�r�yoruz
	{
		if(tara->sonraki != NULL)
			tara = tara->sonraki;
	}
	tara->deger = data;				//mevcut d���mdeki de�eri istenilen ile de�i�tiriyoruz
}

void ArrayList::sil(int n)
{
	if (bas != NULL)									//liste olu�mu� ise
	{
		if (n < sayac)
		{
			int* list;									//yeni i�aret�i olu�turduk
			list = bas;									//yeni i�aret�iyi dizinin ba��na e�itledik
			int konum = 0;
			for (int i = 0; i < n - 1; i++)
			{
				list++;									//i�aret�i ile istenen indise kadar ilerliyoruz
				konum++;
			}
			for (int i = 0; i < (sayac - konum); i++)	//silinen indis de�eri i�in listeyi sola kayd�r�yoruz
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
		cout << endl << "Henuz liste olusturmadiniz!";//list olu�mam��sa uyar� metni
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
	for (int i = 0; i < n - 2; i++)		//istenilen d���me kadar �al��t�r�yoruz
	{
		temp1 = temp1->sonraki;
	}
	Node* temp2 = temp1->sonraki;
	temp1->sonraki = temp2->sonraki;	// �nceki d���m ile sonraki d���m� ba�l�yoruz
	free(temp2);						//istedi�imiz d���m� siliyoruz
}

void ArrayList::yazdir()
{
	int* oku;							//yeni i�aret�i olu�turdum
	oku = bas;							//dizinin ba�lang�� adresine e�itledim
	if (oku != NULL)
	{
		for (int i = 0; i < sayac; i++)
		{
			cout << *oku << " ";		//adresteki de�eri ekrana yaz�yor
			oku++;						//bir sonraki adrese gidiyor +4 byte
		}
		oku = bas;						//yazma i�lemi bittikten sonra ba�lang��a geri d�nd�k
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
		bas = NULL; //ba�lang�� adresini siliyoruz
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
