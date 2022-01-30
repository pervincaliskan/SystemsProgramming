//Pipes(Borular)
//linux os de parent ve child processin pipe araciligla bilgi yazip okudugu C kodu
//fd[0] okuma ucu, fd[1] yazma ucu
//pipe'lar da bir uc okuma bir uc yazmadir
//processler arasi parent child iliskisi olmalidir(alt-üst iliskisi) aksi halde adlandirlmis pipe olur
//Adlandirilmis pipe ise farkli atalara sahip processler arasinda Ipc'yi saglar

//linux os de parent ve child processin pipe araciligla bilgi yazip okudugu C kodu
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	int fd[2],i,pid,d,y,statu;
	char bilgi[18];
	
	
	i = pipe(fd);
	printf("pipe geri donus degeri:%d\n",i);
	
	pid= fork();
	if (pid == 0){
		close(fd[0]); // okuma  fd yi kapat
		d = dup(fd[1]); // pipe'a yazmak icin fd yi kopyala
		printf("dup donus %d\t fd[1] degeri &d\n",d,fd[1] );
		close(fd[1]);
		write(d,"Ben child process\n",18);
	}
	else
		close(fd[1]);// yazma fd yi kapat 
		y = dup(fd[0]); // dup okuma icin 
		printf("dup donus %d\t fd[0] degeri &d\n",y,fd[0] );
			close(fd[0]);
	read(y,bilgi,18);
	printf(bilgi);
}
