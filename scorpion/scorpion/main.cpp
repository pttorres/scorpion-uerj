#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
//#include "RgbImage.h"
#define PI 3.141592654
#include <stdio.h>
#include <stdlib.h>
#include <GL\glut.h>



/////////   VARIÁVEIS GLOBAIS PARA OS ANGULOS////////////
float ang = 180;
float ang2 = 0;
float ang3 = 0;
GLfloat zoom = 55.0;
GLfloat fAspect;

void display();

class Membro
{
public:
	Membro(float a, float l) : largura(l), altura(a), conexcao(0) {}
	void desenha();

	void setConexcao(Membro *membro, float ang) { conexcao = membro, angulo = ang; }

	void setAngulo(float ang) { angulo = ang; }
	float getAngulo() { return angulo; }

protected:
	float largura;
	float altura;

	float angulo;
	Membro *conexcao;
};

void Membro::desenha()
{
	glPushMatrix();  //salva o contexto(1)

	glTranslatef(0.0, altura / 2.0, 0.0); //vai para o meio do Membro

	glPushMatrix();   //salva o contexto(2)
	glScalef(largura, altura, largura);  //escala para o tamanho do Membro

	glutSolidCube(largura);    //desenha o Membro
	glPopMatrix();    //restaura o contexto(2)

	glTranslatef(0.0, altura / 2.0, 0.0); // vai para a ponta do Membro

	glutSolidSphere(0.8*largura, 8, 8);        //desenha a bolinha

	if (conexcao)
	{
		glRotatef(angulo, 1.0, 0.0, 0.0); //rotaciona para o angulo da conexcao
		conexcao->desenha();              //desenha recursivamente
	}

	glPopMatrix();  //restaura o contexto(1)
};
////////////////////////////////////////////////////////////
class Pata
{
public:
	Pata(float comprimento, float largura);
	void desenha() { a.desenha(); }
	void setCurvatura(float curvatura);
	float getCurvatura() { return a.getAngulo() * 100 / 90; }

protected:
	Membro a, b, c;
};

Pata::Pata(float comprimento, float largura)
	: a(comprimento*0.4, largura), b(comprimento*0.35, largura), c(comprimento*0.25, largura)
{
	a.setConexcao(&b, 0.0);
	b.setConexcao(&c, 0.0);
}

void Pata::setCurvatura(float curvatura)
{
	a.setAngulo(curvatura*0.5);
	b.setAngulo(curvatura*0.5);
}

class Garra
{
public:
	Garra(float a, float l) : largura(l), altura(a), conexcao(0) {}
	void desenha();

	void setConexcao(Garra *garra, float ang) { conexcao = garra, angulo = ang; }

	void setAngulo(float ang) { angulo = ang; }
	void setAnguloPinca(float anguloPinca) { angPinca = anguloPinca; }
	float getAngulo() { return angulo; }

protected:
	float largura;
	float altura;

	float angulo;
	float angPinca;
	Garra *conexcao;
};

void Garra::desenha()
{

	float distanciaP1 = 0.9, distanciaP2 = 1.5;
	glPushMatrix();  //salva o contexto(1)
	glTranslatef(0.0, altura / 2.0, 0.0); //vai para o meio do Membro
	glPushMatrix();   //salva o contexto(2)
	glScalef(largura, altura, largura);  //escala para o tamanho do Membro
	glutSolidCube(largura);    //desenha o Membro
	glPopMatrix();    //restaura o contexto(2)
	glTranslatef(0.0, altura / 2.0, 0.0); // vai para a ponta do Membro
	glutSolidSphere(0.8*largura, 8, 8);        //desenha a bolinha
	glRotatef(angulo, 1.0, 0.0, 0.0); //rotaciona para o angulo da conexcao

	//Garra 
	glRotatef(angPinca*distanciaP2, 0, 0, 2.0);
	glPushMatrix();  //salva o contexto(1)
	glTranslatef(0.0, altura / 2.0, 0.0); //vai para o meio do Membro
	glPushMatrix();   //salva o contexto(2)
	glScalef(largura, altura, largura);  //escala para o tamanho do Membro
	glutSolidCube(largura);    //desenha o Membro
	glPopMatrix();    //restaura o contexto(2)
	glTranslatef(0.0, altura / 2.0, 0.0); // vai para a ponta do Membro
	glutSolidSphere(0.8*largura, 8, 8);        //desenha a bolinha

	glRotatef(angPinca*distanciaP1, 0.0, 0.0, -1.0);
	glPushMatrix();  //salva o contexto(1)
	glTranslatef(0.0, altura / 2.0, 0.0); //vai para o meio do Membro
	glPushMatrix();   //salva o contexto(2)
	glScalef(largura, altura, largura);  //escala para o tamanho do Membro
	glutSolidCube(largura);    //desenha o Membro
	glPopMatrix();    //restaura o contexto(2)
	glTranslatef(0.0, altura / 2.0, 0.0); // vai para a ponta do Membro
	glutSolidSphere(0.8*largura, 8, 8);        //desenha a bolinha

	glPopMatrix();
	glPopMatrix();

	glRotatef(angPinca*distanciaP2, 0, 0, -2.0);
	glPushMatrix();  //salva o contexto(1)
	glTranslatef(0.0, altura / 2.0, 0.0); //vai para o meio do Membro
	glPushMatrix();   //salva o contexto(2)
	glScalef(largura, altura, largura);  //escala para o tamanho do Membro
	glutSolidCube(largura);    //desenha o Membro
	glPopMatrix();    //restaura o contexto(2)
	glTranslatef(0.0, altura / 2.0, 0.0); // vai para a ponta do Membro
	glutSolidSphere(0.8*largura, 8, 8);        //desenha a bolinha

	glRotatef(angPinca*distanciaP1, 0.0, 0.0, 1.0);
	glPushMatrix();  //salva o contexto(1)
	glTranslatef(0.0, altura / 2.0, 0.0); //vai para o meio do Membro
	glPushMatrix();   //salva o contexto(2)
	glScalef(largura, altura, largura);  //escala para o tamanho do Membro
	glutSolidCube(largura);    //desenha o Membro
	glPopMatrix();    //restaura o contexto(2)
	glTranslatef(0.0, altura / 2.0, 0.0); // vai para a ponta do Membro
	glutSolidSphere(0.8*largura, 8, 8);        //desenha a bolinha

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();  //restaura o contexto(1) A
};

class Pinca
{
public:
	Pinca(float comprimento, float largura);
	void desenha() { a.desenha(); }
	void setCurvatura(float curvatura);
	float getCurvatura() { return a.getAngulo() * 100 / 90; }

protected:
	Garra a, b;
};



Pinca::Pinca(float comprimento, float largura)
	: a(comprimento*0.4, largura), b(comprimento*0.4, largura)
{
	a.setConexcao(&b, 0.5);
	a.setAnguloPinca(40);
}

void Pinca::setCurvatura(float curvatura)
{
	a.setAngulo(curvatura*0.6);
	a.setAnguloPinca(curvatura*0.6);
	b.setAngulo(curvatura*0.2);
}

//Cauda------------
class Cauda
{
public:
	Cauda(float comprimento, float largura);
	void desenha() { a.desenha(); }
	void setCurvatura(float curvatura);
	float getCurvatura() { return a.getAngulo() * 100 / 90; }

protected:
	Membro a, b, c, d, e;
};

Cauda::Cauda(float comprimento, float largura)
	: a(comprimento*0.45, largura), b(comprimento*0.4, largura), c(comprimento*0.35, largura), d(comprimento*0.3, largura), e(comprimento*0.25, largura)
{
	a.setConexcao(&b, 0.0);
	b.setConexcao(&c, 0.0);
	c.setConexcao(&d, 0.0);
	d.setConexcao(&e, 0.0);
}

void Cauda::setCurvatura(float curvatura)
{
	a.setAngulo(curvatura*0.9);
	b.setAngulo(curvatura*0.9);
	c.setAngulo(curvatura*0.9);
	d.setAngulo(curvatura*0.9);
}

//------------------
class Torax
{
public:
	Torax(float grossura);
	void desenha();
	void setCurvatura(int pata, float curv);
	float getCurvatura(int pata) { return curvatura[pata]; }
	void abrir(bool tudoJunto = false);
	void fechar(bool tudoJunto = false);
	void andar();
protected:
	float grossura;

	Pata trazEsq1;
	Pata trazEsq2;
	Pata trazDir1;
	Pata trazDir2;
	Pata dianEsq1;
	Pata dianEsq2;
	Pata dianDir1;
	Pata dianDir2;

	Pinca pincaDir;
	Pinca pincaEsq;
	Pinca garraDir;

	Cauda cauda;

	float curvatura[11];
};

/*Cria a estrutura e define o tamanho das patas*/
Torax::Torax(float gros)
	: grossura(gros),
	trazEsq1(7 * grossura, grossura*0.8),
	trazEsq2(7 * grossura, grossura*0.8),
	trazDir1(7 * grossura, grossura*0.8),
	trazDir2(7 * grossura, grossura*0.8),
	dianEsq1(6 * grossura, grossura*0.8),
	dianEsq2(5 * grossura, grossura*0.8),
	dianDir1(6 * grossura, grossura*0.8),
	dianDir2(5 * grossura, grossura*0.8),
	pincaDir(6 * grossura, grossura*0.8),
	pincaEsq(6 * grossura, grossura*0.8),
	garraDir(6 * grossura, grossura*0.8),
	cauda(-5 * grossura, grossura)
{
	for (int i = 0; i < 13; i++)
		curvatura[i] = 0;
}


void Torax::desenha()
{
	/*Desenhando as pinças*/
	glPushMatrix();
	glTranslatef(0.0, 3.0, 0.0);
	glPushMatrix();
	glTranslatef(-1.8, 0.0, 0.0);
	glutSolidSphere(grossura, 3, 3);
	glRotatef(100, 0.0, 0.0, 1.0);
	glRotatef(-160, 1.0, 1.0, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.9*grossura, 8, 8);
	pincaEsq.desenha();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.8, 0.0, 0.0);
	glutSolidSphere(grossura, 3, 3);
	glRotatef(100, 0.0, 0.0, 5.0);
	glRotatef(-160, 1.0, 0.6, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.9*grossura, 8, 8);
	pincaDir.desenha();

	glPopMatrix();
	glPopMatrix();

	/*Desenhando patas do lado Esquerdo*/
	glPushMatrix();
	glTranslatef(-2.0*grossura, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.0, -3.0, 0.0);
	glutSolidSphere(grossura, 3, 3);
	glRotatef(80, 0.0, 0.0, 1.0);
	glRotatef(20, 0.0, 1.0, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.9*grossura, 8, 8);
	trazEsq1.desenha();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glutSolidSphere(grossura, 3, 3);
	glRotatef(80, 0.0, 0.0, 1.0);
	glRotatef(20, 0.0, 1.0, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.9*grossura, 8, 8);
	trazEsq2.desenha();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	glutSolidSphere(grossura, 3, 3);
	glRotatef(80, 0.0, 0.0, 1.0);
	glRotatef(20, 0.0, 1.0, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.9*grossura, 8, 8);
	dianEsq1.desenha();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, 3.0, 0.0);
	glutSolidSphere(grossura, 3, 3);
	glRotatef(80, 0.0, 0.0, 1.0);
	glRotatef(20, 0.0, 1.0, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.9*grossura, 8, 8);
	dianEsq2.desenha();
	glPopMatrix();
	glPopMatrix();

	/*Desenhando o Torax*/
	glPushMatrix();
	glScalef(3 * grossura, 8 * grossura, 1.25*grossura);
	glutSolidCube(1.0);
	glPopMatrix();

	/*Desenhando a cauda */
	glPushMatrix();
	glTranslatef(0.0, -4.0, 0.0);
	glutSolidSphere(grossura, 8, 8);
	cauda.desenha();
	glPopMatrix();

	/*Desenhando patas do lado direito*/
	glTranslatef(2.0*grossura, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.0, -3.0, 0.0);
	glutSolidSphere(grossura, 3, 3);
	glRotatef(-80, 0.0, 0.0, 1.0);
	glRotatef(-20, 0.0, 1.0, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.9*grossura, 8, 8);
	trazDir1.desenha();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glutSolidSphere(grossura, 3, 3);
	glRotatef(-80, 0.0, 0.0, 1.0);
	glRotatef(-20, 0.0, 1.0, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.9*grossura, 8, 8);
	trazDir2.desenha();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	glutSolidSphere(grossura, 3, 3);
	glRotatef(-80, 0.0, 0.0, 1.0);
	glRotatef(-20, 0.0, 1.0, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.9*grossura, 8, 8);
	dianDir1.desenha();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, 3.0, 0.0);
	glutSolidSphere(grossura, 3, 3);
	glRotatef(-80, 0.0, 0.0, 1.0);
	glRotatef(-20, 0.0, 1.0, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.9*grossura, 8, 8);
	dianDir2.desenha();
	glPopMatrix();
	glPopMatrix();

}

//TODO: Remover curvatura da cauda do array. Deve ser uma propriedade da cauda
void Torax::setCurvatura(int pata, float curv)
{
	curvatura[pata] = curv;

	switch (pata)
	{
	case 0: trazEsq1.setCurvatura(curv); break;
	case 1: trazEsq2.setCurvatura(curv); break;
	case 2: dianEsq1.setCurvatura(curv); break;
	case 3: dianEsq2.setCurvatura(curv); break;
	case 4: trazDir1.setCurvatura(curv); break;
	case 5: trazDir2.setCurvatura(curv); break;
	case 6: dianDir1.setCurvatura(curv); break;
	case 7: dianDir2.setCurvatura(curv); break;
	case 8: cauda.setCurvatura(curv); break;
	case 9: pincaEsq.setCurvatura(curv); break;
	case 10: pincaDir.setCurvatura(curv); break;
	}
}

void Torax::abrir(bool tudoJunto)
{
	if (tudoJunto)
		for (int j = getCurvatura(1); j >= 0; j -= 7)
		{
			for (int i = 7; i >= 0; i--)
			{
				setCurvatura(i, j);

			}
			display();
		}
	else
		for (int i = 7; i >= 0; i--)
		{
			for (int j = getCurvatura(i); j >= 0; j -= 7)
			{
				setCurvatura(i, j);
				display();
			}
		}

}

void Torax::fechar(bool tudoJunto)
{
	if (tudoJunto)
		for (int j = getCurvatura(1); j <= 100; j += 7)
		{
			for (int i = 0; i < 8; i++)
			{
				setCurvatura(i, j);
			}
			display();
		}
	else
		for (int i = 0; i < 8; i++)
		{
			for (int j = getCurvatura(i); j <= 100; j += 7)
			{
				setCurvatura(i, j);
				display();
			}
		}
}

/////////////////////////////////////////////////////////////
Torax t(1.0);

bool andarAux = false;
void Torax::andar()
{
	float curv = t.getCurvatura(0);
	float curvOne = 64, curvTwo = 56, curvThree = 48;

	for (int i = 0; i < 8; i++)
	{
		if ((t.getCurvatura(i) != curvOne && t.getCurvatura(i) != curvTwo && t.getCurvatura(i) != curvThree) || (i > 0 && curv != t.getCurvatura(i)))
		{
			for (int j = 0; j < 8; j++)
				t.setCurvatura(j, curvOne);
			curv = curvOne;
			andarAux = false;
		}
	}

	if (andarAux)
		curv += 8;
	else
		curv -= 8;

	for (int i = 0; i < 4; i++)
	{
		t.setCurvatura(i, curv);
		t.setCurvatura(4 + i, curv);
	}

	if (curv == curvThree)
		andarAux = true;

	if (curv == curvOne)
		andarAux = false;
}

void defineCurvaturaInicial()
{
	t.setCurvatura(8, 56); //define a posição inicial da cauda
	for (int i = 0; i < 8; i++)
		t.setCurvatura(i, 64); //define a posição inicial das patas
}

///////////////////////////////////////////////////
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LEQUAL);				// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
	glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

	defineCurvaturaInicial();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//////////////ISSO AQUI EH PRA LUZ///////////E EU AINDA N SEI COMO FUNCA/////
	GLfloat			diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0 };
	GLfloat			ambientLight[] = { 0.2f, 0.2f, 0.4f, 1.0 };
	GLfloat			lightPos[] = { 0.0f, 500.0f, 100.0f, 1.0f };
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, diffuseLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.0f, 1.0f, 1.0f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, diffuseLight);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 50);
	//////////////////////////////////////////////////////////////////////////

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(zoom, fAspect, 1.0, 40.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);

	glPushMatrix();

	glTranslatef(0.0, -2.0, -15.0);
	glRotatef(ang3, 0.0, 0.0, 1.0);
	glRotatef(ang, 0.0, 1.0, 0.0);
	glRotatef(ang2, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.8, 0);

	t.desenha();

	glPopMatrix();

	glutSwapBuffers();
}

// Função callback chamada quando o tamanho da janela é alterado
void reshape(GLsizei w, GLsizei h)
{
	if (h == 0) h = 1;

	glViewport(0, 0, w, h);

	fAspect = (GLfloat)w / (GLfloat)h;
	glutPostRedisplay();
}

void idle()
{
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		if (t.getCurvatura(0) < 100)
			t.setCurvatura(0, t.getCurvatura(0) + 8);
		break;
	case 'a':
		if (t.getCurvatura(0) > 0)
			t.setCurvatura(0, t.getCurvatura(0) - 8);
		break;
	case 'w':
		if (t.getCurvatura(1) < 100)
			t.setCurvatura(1, t.getCurvatura(1) + 8);
		break;
	case 's':
		if (t.getCurvatura(1) > 0)
			t.setCurvatura(1, t.getCurvatura(1) - 8);
		break;
	case 'e':
		if (t.getCurvatura(2) < 100)
			t.setCurvatura(2, t.getCurvatura(2) + 8);
		break;
	case 'd':
		if (t.getCurvatura(2) > 0)
			t.setCurvatura(2, t.getCurvatura(2) - 8);
		break;
	case 'r':
		if (t.getCurvatura(3) < 100)
			t.setCurvatura(3, t.getCurvatura(3) + 8);
		break;
	case 'f':
		if (t.getCurvatura(3) > 0)
			t.setCurvatura(3, t.getCurvatura(3) - 8);
		break;
	case 't':
		if (t.getCurvatura(4) < 100)
			t.setCurvatura(4, t.getCurvatura(4) + 8);
		break;
	case 'g':
		if (t.getCurvatura(4) > 0)
			t.setCurvatura(4, t.getCurvatura(4) - 8);
		break;
	case 'y':
		if (t.getCurvatura(5) < 100)
			t.setCurvatura(5, t.getCurvatura(5) + 8);
		break;
	case 'h':
		if (t.getCurvatura(5) > 0)
			t.setCurvatura(5, t.getCurvatura(5) - 8);
		break;
	case 'u':
		if (t.getCurvatura(6) < 100)
			t.setCurvatura(6, t.getCurvatura(6) + 8);
		break;
	case 'j':
		if (t.getCurvatura(6) > 0)
			t.setCurvatura(6, t.getCurvatura(6) - 8);
		break;
	case 'i':
		if (t.getCurvatura(7) < 100)
			t.setCurvatura(7, t.getCurvatura(7) + 8);
		break;
	case 'k':
		if (t.getCurvatura(7) > 0)
			t.setCurvatura(7, t.getCurvatura(8) - 8);
		break;
	case 'o':
		if (t.getCurvatura(8) < 65)
			t.setCurvatura(8, t.getCurvatura(8) + 7);
		break;
	case 'l':
		if (t.getCurvatura(8) > 0)
			t.setCurvatura(8, t.getCurvatura(8) - 7);
		break;
	case 'z':
		t.andar();
		break;
	case '.': //>
		ang += 5;
		if (ang > 360)
			ang -= 360;
		break;
	case ',': //<
		ang -= 5;
		if (ang < 0)
			ang += 360;
		break;
	case ']':
		ang2 += 5;
		if (ang2 > 360)
			ang2 -= 360;
		break;
	case '[':
		ang2 -= 5;
		if (ang2 < 0)
			ang2 += 360;
		break;
	case '+':
		t.abrir();
		break;
	case '*':
		t.abrir(true);
		break;
	case '/':
		t.fechar(true);
		break;
	case '-':
		t.fechar();
		break;
	case 27: //ESC
		exit(0);
		break;
	case '9':
		ang3 += 5;
		if (ang3 > 360)
			ang3 -= 360;
		break;
	case '0':
		ang -= 5;
		if (ang < 0)
			ang += 360;
		break;
	case 'v':
		ang += 5;
		if (ang > 360)
			ang -= 360;
		break;
	default:
		return;
	}
	glutPostRedisplay();
}

void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) { // Zoom-in
			if (zoom >= 10) zoom -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) { // Zoom-out
			if (zoom <= 130) zoom += 5;
		}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(200, 200);
	glutCreateWindow(argv[0]);
	init();

	printf("FullScreen?(y/n) ");
	if (getchar() == 'y')
		glutFullScreen();

	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(GerenciaMouse);
	glutMainLoop();
	return 0;
}