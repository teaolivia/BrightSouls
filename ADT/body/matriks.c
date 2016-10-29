// Nama : Kevin Iswara
// NIM : 13515085
// Topik : Pra-Praktikum 4
// Tanggal : 14 September 2016
// Deskripsi : membuat body dr matriks

#include <stdio.h>
#include "/ADT/header/boolean.h"
#include "/ADT/header/matriks.h"
#include <math.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	indeks i,j;
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
	for(i=1;i<=NBrsEff(*M);i++){
		for(j=1;j<=NKolEff(*M);j++){
			Elmt(*M,i,j) = 0;
		}
	}
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
	return (i >= BrsMin && i <= BrsMax && j <= KolMax && j >= KolMin);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
	return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
	return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
	return NBrsEff(M);
}
indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
	return NKolEff(M);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
	return (i>=GetFirstIdxBrs(M) && i<=GetLastIdxBrs(M) && j>=GetFirstIdxKol(M) && j<=GetLastIdxKol(M));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
	return (Elmt(M,i,i));
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
	indeks i,j;
	NBrsEff(*MHsl) = NBrsEff(MIn);
	NKolEff(*MHsl) = NKolEff(MIn);
	for (i=GetFirstIdxBrs(*MHsl); i<=GetLastIdxBrs(*MHsl); i++){
		for (j=GetFirstIdxKol(*MHsl); j<=GetLastIdxKol(*MHsl); j++){
			Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
		}
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
	indeks i,j;
	if (IsIdxValid(NB,NK)){
		MakeMATRIKS(NB, NK, M);
		for (i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++){
			for (j=GetFirstIdxKol(*M); j<=GetLastIdxKol(*M); j++){
				if (j!=GetLastIdxKol(*M)){
					scanf("%d ",&Elmt(*M,i,j));
				}
				else {
					scanf("%d",&Elmt(*M,i,j));
				}
			}
		}
	}
}
void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
	indeks i,j;
	for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
		for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
			if (j!=GetLastIdxKol(M)){
				printf("%d ",Elmt(M,i,j));
			}
			else {
				if ((i == GetLastIdxBrs(M))){
					printf("%d",Elmt(M,i,j));
				}
				else printf("%d\n",Elmt(M,i,j));
			}
		}
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
	MATRIKS M;
	indeks i,j;
	if ((GetFirstIdxBrs(M1) == GetFirstIdxBrs(M2)) && (GetLastIdxBrs(M1) == GetLastIdxBrs(M2))){
		NBrsEff(M) = NBrsEff(M1);
		NKolEff(M) = NKolEff(M1);
		for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
			for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
				Elmt(M,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
			}
		}
	}
	return M;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 â€“ M2 */ 
	MATRIKS M;
	indeks i,j;
	if ((GetFirstIdxBrs(M1) == GetFirstIdxBrs(M2)) && (GetLastIdxBrs(M1) == GetLastIdxBrs(M2))){
		NBrsEff(M) = NBrsEff(M1);
		NKolEff(M) = NKolEff(M1);
		for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
			for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
				Elmt(M,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
			}
		}
	}
	return M;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
	MATRIKS M;
	int i, j, k;
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
			Elmt(M, i, j) = 0;
			for (k = GetFirstIdxKol(M1); k <= GetLastIdxBrs(M2); k++) {
				Elmt(M, i, j) = Elmt(M, i, j) + Elmt(M1, i, k) * Elmt(M2, k, j);
			}
		}
	}
	return M;
}
MATRIKS KaliKons (MATRIKS M, ElType X){
/* Mengirim hasil perkalian setiap elemen M dengan X */
	indeks i,j;
	for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
		for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
			Elmt(M,i,j) = Elmt(M,i,j) * X;
		}
	}
	return M;
}
void PKaliKons (MATRIKS * M, ElType K){
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
	indeks i,j;
	for (i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++){
		for (j=GetFirstIdxKol(*M); j<=GetLastIdxKol(*M); j++){
			Elmt(*M,i,j) = Elmt(*M,i,j) * K;
		}
	}
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
   boolean cek;
   indeks i,j;
   cek = true;
   if(NBElmt(M1) == NBElmt(M2)){
   		i=GetFirstIdxBrs(M1) - 1;
   		while(cek && i<GetLastIdxBrs(M1)){
			i++;
   			j=GetFirstIdxKol(M1) - 1;
   			while(cek && j<GetLastIdxKol(M2)){
				j++;
   				if (Elmt(M1,i,j) != Elmt(M2,i,j)){
   					cek = false;
				}
			}
		}
   }
   else (cek = false);
   return cek;
}
boolean NEQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 tidak sama dengan M2 */
	return (!EQ(M1,M2));
}
boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */
	return NBrsEff(M) * NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
	return (NBrsEff(M) == NKolEff(M));
}
boolean IsSimetri (MATRIKS M){
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
   boolean cek;
   indeks i,j;
   if (IsBujurSangkar(M)){
   		cek = true;
   		i=GetFirstIdxBrs(M)-1;
   		while(cek && i<GetLastIdxBrs(M)){
			i++;
   			j=GetFirstIdxKol(M)-1;
   			while(cek && j<GetLastIdxKol(M)){
				j++;
   				if (Elmt(M,i,j) != Elmt(M,j,i)){
   					cek = false;
				}
			}
		}
   }
   else (cek = false);
   return cek;
}
boolean IsSatuan (MATRIKS M){
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
   boolean cek;
   indeks i,j;
   if (IsBujurSangkar(M)){
   		cek = true;
   		i=GetFirstIdxBrs(M)-1;
   		while(cek && i<GetLastIdxBrs(M)){
			i++;
   			j=GetFirstIdxKol(M)-1;
   			while(cek && j<GetLastIdxKol(M)){
				j++;
   				if (i==j){
   					if(Elmt(M,i,j) != 1){
   						cek = false;
					}
				}
				else {
					if(Elmt(M,i,j) != 0){
						cek = false;
					}
				}
			}
		}
   }
   else (cek = false);
   return cek;
}
boolean IsSparse (MATRIKS M){
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
   indeks i,j,max,jum;
   boolean cek;
   max = NBElmt(M) / 20;
   jum = 0;
   for(i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
   		for(j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
   			if(Elmt(M,i,j) != 0){
   				jum++;
			}
		}
   }
   if(jum<=max){
   	return true;
   }
   else return false;
}
MATRIKS Inverse1 (MATRIKS M){
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
	return (KaliKons(M,(-1)));
}
float Determinan (MATRIKS M){
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
	indeks i,j,k,l,x,y,a,b;
	float tambah, kurang, kali;
	tambah = 0;
	kurang = 0;
	if(NBrsEff(M) == 1){
		return (Elmt(M,i,j));
	}
	else if(NBrsEff(M) == 2){
		return ((Elmt(M,1,1)) * (Elmt(M,2,2)) - (Elmt(M,1,2) * (Elmt(M,2,1))));
	}
	else if(NBrsEff(M) == 3){for(k=GetFirstIdxKol(M); k<=GetLastIdxKol(M); k++){
   		j=k;
   		kali = 1;
   		for(i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
   			if (i > (GetLastIdxBrs(M))){
   				x = i % (GetLastIdxBrs(M));
			}
			else x = i;
   			if (j > (GetLastIdxKol(M))){
   				y = j % (GetLastIdxKol(M));
			}
			else y = j;
   			kali = kali * Elmt(M,x,y);
   			j++;
		}
		tambah = tambah + kali;
	}
		for(k=GetFirstIdxKol(M); k<=GetLastIdxKol(M); k++){
   			j=k;
   			kali = 1;
   			for(i=GetLastIdxBrs(M); i>=GetFirstIdxBrs(M); i--){
				x = i;
	   			if ((j > (GetLastIdxKol(M))) && (j!=(GetLastIdxKol(M)))){
	   				y = j % (GetLastIdxKol(M));
				}
				else y = j;
	   			kali = kali * Elmt(M,x,y);
	   			j++;
			}
			kurang = kurang + kali;
		}
	return (tambah - kurang);
	}
	else {
		float sum;
		MATRIKS buff;
		if(NBrsEff(M)==2)
		{
			return ((Elmt(M,1,1)*Elmt(M,2,2))-(Elmt(M,1,2)*Elmt(M,2,1)));
		}
		else
		{
			sum=0;
			i=1;
			for(j=GetFirstIdxBrs(M);j<=GetLastIdxBrs(M);j++)
			{
						a=GetFirstIdxBrs(M);
						MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1,&buff);
						for(k=GetFirstIdxBrs(M);k<=GetLastIdxBrs(M);k++)
						{
							if(k!=i) 
							{
								b=GetFirstIdxKol(M);
								for(l=GetFirstIdxKol(M);l<=GetLastIdxKol(M);l++){
									if(l!=j)
										{
											Elmt(buff,a,b)=Elmt(M,k,l);
											b++;
										}
								}
								a++;
							}
						}
						sum+=pow(-1,i+j)*Elmt(M,i,j)*Determinan(buff);
					
			}
			return sum;
			
		}
	}
}
void PInverse1 (MATRIKS * M){
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
	*M = Inverse1(*M);
}
void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
	MATRIKS Mhsl;
	indeks i,j;
	NBrsEff(Mhsl) = NKolEff(*M);
	NKolEff(Mhsl) = NBrsEff(*M);
	for(i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++){
   		for(j=GetFirstIdxKol(*M); j<=GetLastIdxKol(*M); j++){
   			Elmt(Mhsl,i,j) = Elmt (*M,j,i);
		}
   }
   *M = Mhsl;
}
/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i){
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
    float jum;
    indeks j;
    for(j=1;j<=NKolEff(M);j++){
        jum = jum + Elmt(M,i,j);
    }
    return(jum / NKolEff(M));
}

float RataKol (MATRIKS M, indeks j){
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
    float jum;
    indeks i;
    jum = 0;
    for(i=1;i<=NBrsEff(M);i++){
        jum = jum + Elmt(M,i,j);
    }
    return(jum / NBrsEff(M));
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
    ElType max1, min1;
    indeks j;
    max1 = Elmt(M,i,GetFirstIdxKol(M));
    min1 = Elmt(M,i,GetFirstIdxKol(M));
    for(j=(GetFirstIdxKol(M)+1);j<=NKolEff(M);j++){
        if(Elmt(M,i,j)>=max1){
            max1 = Elmt(M,i,j);
        }
        if(Elmt(M,i,j)<=min1){
            min1 = Elmt(M,i,j);
        }
    }
    *max = max1;
    *min = min1;
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
    ElType max1, min1;
    indeks i;
    max1 = Elmt(M,GetFirstIdxBrs(M),j);
    min1 = Elmt(M,GetFirstIdxBrs(M),j);
    for(i=(GetFirstIdxBrs(M)+1);i<=NBrsEff(M);i++){
        if(Elmt(M,i,j)>=max1){
            max1 = Elmt(M,i,j);
        }
        if(Elmt(M,i,j)<=min1){
            min1 = Elmt(M,i,j);
        }
    }
    *max = max1;
    *min = min1;
}

int CountXBrs (MATRIKS M, indeks i, ElType X){
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
    int count;
    indeks j;
    count = 0;
    for(j=GetFirstIdxKol(M);j<=NKolEff(M);j++){
        if(Elmt(M,i,j) == X){
            count++;
        }
    }
    return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X){
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
    int count;
    indeks i;
    count = 0;
    for(i=GetFirstIdxBrs(M);i<=NBrsEff(M);i++){
        if(Elmt(M,i,j) == X){
            count++;
        }
    }
    return count;
}