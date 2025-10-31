#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M_PI 3.141592653589793

int factorial(int a) {
	if(a==1 || a==0) return 1;
	else return a * factorial(a-1);
}
int fpb(int a, int b){
    if (b == 0) return a; 
    else return fpb(b, a % b);
}

int main() {
	int input;
	while (1) {
		printf("\n===Calculator===\n");
		printf("1. Basic Calculator (+ - * /)\n");
		printf("2. Scientific Calculator (sin cos tan log sqrt factorial)\n");
		printf("3. Matrix Multiplication\n");
		printf("4. Volume Calculator\n");
		printf("5. FPB\n");
		printf("6. Elimination Calculator\n");
		printf("Quit(0)\n");
		printf("Choose an option: ");
		scanf("%d", &input);

		if (input == 0) {
		    #ifdef _WIN32
                system("cls");  
            #else
                system("clear"); 
            #endif
			printf("Thank you!\n");
			break;
		}

		if (input == 1) {
			int n;
			printf("\n===Basic Calculator===\n");
			printf("Back to Menu (0)\n");
			printf("How many operations you want to use: ");
			scanf("%d", &n);
			while (1) {
				if(n == 0) {
					printf("Returning to main menu...\n");
					#ifdef _WIN32
                        system("cls"); 
                    #else
                        system("clear"); 
                    #endif
					break;
				}

				printf("Enter your expression (e.g., 3 + 5 - 2 * 4 / 2): ");
				char op[n];
				double result;
				double num[n+1];

				for(int i=0; i<n; i++) {
					scanf("%lf", &num[i]);
					scanf(" %c", &op[i]);
				}
				scanf("%lf", &num[n]);

				for(int i=n-1; i>=0; i--) {
					if(op[i] == '*' || op[i] == '/') {
						if(op[i] == '*') {
							result = num[i]*num[i+1];
							num[i] = result;
							op[i] = '+';
							num[i+1] = 0;
						}
						else {
							result = num[i]/num[i+1];
							num[i] = result;
							op[i] = '+';
							num[i+1] = 0;
						}
					}
				}

				double ans = num[0];
				for(int i=0; i<n; i++) {
					if(op[i] == '+') {
						ans = ans + num[i+1];
					} else if(op[i] == '-') {
						ans = ans - num[i+1];
					}
				}

				printf("Result: ");
				if(ans == (int)ans) {
					printf("%d\n", (int)ans);
				} else {
					printf("%.2lf\n", ans);
				}
				printf("\n===Basic Calculator===\n");
				printf("Back to Menu (0)\n");
				printf("How many operations you want to use: ");
				scanf("%d", &n);
			}
		}
		else if (input == 2) {
			int input2;
			printf("===Scientific Calculator===\n");
			printf("1. sin\n");
			printf("2. cos\n");
			printf("3. tan\n");
			printf("4. log\n");
			printf("5. sqrt\n");
			printf("6. Factorial\n");
			printf("Back to Menu (0)\n");
			printf("Choose an option: ");
			scanf("%d", &input2);
			while (1) {
				if(input2 == 0) {
					printf("Returning to main menu...\n");
					#ifdef _WIN32
                        system("cls");  
                    #else
                        system("clear"); 
                    #endif
					break;
				}

				if(input2 == 1) {
					double angle, result;
					printf("Enter angle in degrees: ");
					scanf("%lf", &angle);
					result = sin(angle * M_PI / 180.0);
					printf("Result: %lf\n", result);
				}

				else if(input2 == 2) {
					double angle, result;
					printf("Enter angle in degrees: ");
					scanf("%lf", &angle);
					result = cos(angle * M_PI / 180.0);
					printf("Result: %lf\n",result);
				}

				else if(input2 == 3) {
					double angle, result;
					printf("Enter angle in degrees: ");
					scanf("%lf", &angle);
					result = tan(angle * M_PI / 180.0);
					printf("Result: %lf\n", result);
				}

				else if(input2 == 4) {
					double value, result;
					printf("Enter a positive number: ");
					scanf("%lf", &value);
					if(value > 0) {
						result = log(value);
						printf("Result: %lf\n",result);
					} else {
						printf("Error: Undefined.\n");
					}
				}

				else if(input2 == 5) {
					double value, result;
					printf("Enter a non-negative number: ");
					scanf("%lf", &value);

					if(value >= 0) {
						result = sqrt(value);
						printf("Result: %lf\n",result);
					}

					else {
						printf("Error: Undefined.\n");
					}
				}
				else if (input2==6) {
					int f;
					printf("Input : ");
					scanf("%d", &f);
					printf("Result : %d\n", factorial(f));
				}

				else if(input2 == 0) {
					printf("Returning to main menu...\n");
					break;

				}
				else {
					printf("Invalid\n");
				}
				printf("===Scientific Calculator===\n");
				printf("1. sin\n");
				printf("2. cos\n");
				printf("3. tan\n");
				printf("4. log\n");
				printf("5. sqrt\n");
				printf("6. Factorial\n");
				printf("Back to Menu (0)\n");
				printf("Choose an option: ");
				scanf("%d", &input2);
			}
		}
		else if (input == 3) {
			int r1, c1, r2, c2;
			while (1) {
				printf("\n===Matrix Multiplication===\n");
				printf("Back to Menu (0 0)\n");
				printf("Input Row and Column Matrix 1 : ");
				scanf("%d %d", &r1, &c1);

				if(r1 == 0) {
					printf("Returning to main menu...\n");
					#ifdef _WIN32
                        system("cls");  
                    #else
                        system("clear"); 
                    #endif
					break;
				}

				printf("Input Row and Column Matrix 2 : ");
				scanf("%d %d", &r2, &c2);

				if (c1 != r2) {
					printf("Error: Invalid matriks size!\n");
					continue;
				}

				int matriks1[r1][c1];
				int matriks2[r2][c2];
				int hasil[r1][c2];

				printf("Input Matrix 1 :\n");
				for (int i = 0; i < r1; i++) {
					for (int j = 0; j < c1; j++) {
						scanf("%d", &matriks1[i][j]);
					}
				}

				printf("Input Matrix 2 :\n");
				for (int i = 0; i < r2; i++) {
					for (int j = 0; j < c2; j++) {
						scanf("%d", &matriks2[i][j]);
					}
				}

				for (int i = 0; i < r1; i++) {
					for (int j = 0; j < c2; j++) {
						hasil[i][j] = 0;
						for (int k = 0; k < c1; k++) {
							hasil[i][j] += matriks1[i][k] * matriks2[k][j];
						}
					}
				}

				printf("\nResult :\n");
				for (int i = 0; i < r1; i++) {
					for (int j = 0; j < c2; j++) {
						printf("%d ", hasil[i][j]);
					}
					printf("\n");
				}
			}
		}
		else if (input == 4) {
			int input3;
			printf("===Volume Calculator===\n");
			printf("1. Kubus\n");
			printf("2. Balok\n");
			printf("3. Tabung\n");
			printf("4. Bola\n");
			printf("5. Kerucut\n");
			printf("6. Limas\n");
			printf("7. Prisma Segitiga\n");
			printf("Back to Menu (0)\n");
			printf("Choose an option: ");
			scanf("%d", &input3);
			while (1) {
				if(input3 == 0) {
					printf("Returning to main menu...\n");
					#ifdef _WIN32
                        system("cls");  
                    #else
                        system("clear"); 
                    #endif
					break;
				}

				if(input3 == 1) {
					double sisi, ans;
					printf("Masukkan panjang sisi kubus: ");
					scanf("%lf", &sisi);
					ans = sisi*sisi*sisi;
					if(ans == (int)ans) printf("Result : %d\n", (int)ans);
					else printf("Result : %.2lf\n", ans);
				}

				else if(input3 == 2) {
					double panjang,lebar,tinggi, ans;
					printf("Masukkan panjang, lebar dan tinggi balok : ");
					scanf("%lf %lf %lf", &panjang, &lebar, &tinggi);
					ans = panjang*lebar*tinggi;
					if(ans == (int)ans) printf("Result : %d\n", (int)ans);
					else printf("Result : %.2lf\n", ans);
				}

				else if(input3 == 3) {
					double jari, tinggi, ans;
					printf("Masukkan jari-jari dan tinggi tabung : ");
					scanf("%lf %lf", &jari, &tinggi);
					ans = M_PI * jari * jari * tinggi;
					if(ans == (int)ans) printf("Result : %d\n", (int)ans);
					else printf("Result : %.2lf\n", ans);
				}

				else if(input3 == 4) {
					double jari, ans;
					printf("Masukkan jari-jari bola : ");
					scanf("%lf", &jari);
					ans = 4.0/3.0 * M_PI * jari * jari * jari;
					if(ans == (int)ans) printf("Result : %d\n", (int)ans);
					else printf("Result : %.2lf\n", ans);
				}

				else if(input3 == 5) {
					double jari_alas, tinggi, ans;
					printf("Masukkan jari-jari alas dan tinggi kerucut : ");
					scanf("%lf %lf", &jari_alas, &tinggi);
					ans = M_PI * jari_alas * jari_alas * tinggi * 1.0/3.0;
					if(ans == (int)ans) printf("Result : %d\n", (int)ans);
					else printf("Result : %.2lf\n", ans);
				}
				
				else if(input3 == 6) {
				    int kode;double ans,tinggi;
					printf("1. Limas Persegi\n");
					printf("2. Limas Persegi panjang\n");
					printf("3. Limas Segitiga\n");
					printf("Masukkan kode limas :");
					scanf("%d", &kode);
					switch (kode) {
					    case 1 :
					    double sisi;
					    printf("Masukkan sisi alas dan tinggi limas: ");
					    scanf("%lf %lf", &sisi, &tinggi);
					    ans = 1.0/3.0 * sisi * sisi * tinggi;
					    if(ans == (int)ans) printf("Result : %d\n", (int)ans);
					    else printf("Result : %.2lf\n", ans);
					    break;
    					    
					    case 2 : 
				        double panjang, lebar;
					    printf("Masukkan panjang alas, lebar alas dan tinggi limas: ");
					    scanf("%lf %lf %lf", &panjang, &lebar, &tinggi);
					    ans = 1.0/3.0 * panjang * lebar * tinggi;
					    if(ans == (int)ans) printf("Result : %d\n", (int)ans);
					    else printf("Result : %.2lf\n", ans);
					    break;
    					    
    					case 3 : 
				        double alas, tinggiAlas;
					    printf("Masukkan panjang alas, tinggi alas dan tinggi limas: ");
					    scanf("%lf %lf %lf", &alas,&tinggiAlas, &tinggi);
					    ans = 1.0/6.0 * alas * tinggiAlas * tinggi;
					    if(ans == (int)ans) printf("Result : %d\n", (int)ans);
					    else printf("Result : %.2lf\n", ans);
					    break;
					}
				}
				
				else if(input3 == 7) {
				    double alas,tinggiAlas,tinggi, ans;
					printf("Masukkan panjang alas, tinggi alas dan tinggi prisma : ");
					scanf("%lf %lf %lf", &alas, &tinggiAlas, &tinggi);
					ans = 0.5 * alas*tinggiAlas*tinggi;
					if(ans == (int)ans) printf("Result : %d\n", (int)ans);
					else printf("Result : %.2lf\n", ans);
				}
					
				else if(input3 == 0) {
					printf("Returning to main menu...\n");
					break;

				}
				else {
					printf("Invalid\n");
				}
				printf("===Volums Calculator===\n");
    			printf("1. Kubus\n");
    			printf("2. Balok\n");
    			printf("3. Tabung\n");
    			printf("4. Bola\n");
    			printf("5. Kerucut\n");
    			printf("6. Limas\n");
    			printf("7. Prisma Segitiga\n");
    			printf("Back to Menu (0)\n");
    			printf("Choose an option: ");
    			scanf("%d", &input3);
			}
		}
		else if (input == 5) {
		    int angka1,angka2,ans;
			while (1) {
				printf("\n===FPB===\n");
				printf("Back to Menu (0 0)\n");
				printf("Input number 1 and number 2 : ");
				scanf("%d %d", &angka1, &angka2);

				if(angka1 == 0 && angka2 == 0) {
					printf("Returning to main menu...\n");
					#ifdef _WIN32
                        system("cls");  
                    #else
                        system("clear"); 
                    #endif
					break;
				}
				ans = fpb(angka1,angka2);
				printf("Result : %d\n", ans);
			}
		}
		else if (input == 6) {
		    while (1) {
    int n;
    printf("\n===Elimination Calculator===\n");
    printf("Back to Menu (0)\n");
    printf("How Much Variable : ");
    scanf("%d", &n);
    if(n == 0) {
        printf("Returning to main menu...\n");
        #ifdef _WIN32
            system("cls");  
        #else
            system("clear"); 
        #endif
        break;
    }
    double m[n][n+1];
    for (int i=0;i<n;i++) {
        printf("Input augmented matrix line %d (ex: 1 1 2 5): ", i+1);
        for(int j=0;j<=n;j++) {
            scanf("%lf", &m[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        double temp[n+1];
        
        if (m[i][i] == 0) {
            printf("Error: Zero pivot encountered.\n");
            break;
        }
        
        if (m[i][i] != 1) {
            double bagi = m[i][i];
            for (int j = 0; j <= n; j++) {
                m[i][j] /= bagi;
                temp[j] = m[i][j];
            }
        } else {
            for (int j = 0; j <= n; j++) {
                temp[j] = m[i][j];
            }
        }
        
        for (int k = i + 1; k < n; k++) {
            double factor = m[k][i];
            for (int o = 0; o <= n; o++) {
                m[k][o] -= factor * temp[o];
            }
        }
    }
    
    double ans[n];
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = m[i][n];
        for (int j = i + 1; j < n; j++) {
            ans[i] -= m[i][j] * ans[j];
        }
    }
    
    printf("\n=== Result ===\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2lf\n", i + 1, ans[i]);
    }
}
		}
		printf("\n");
	}
}