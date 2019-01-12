/*#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
//#include "RgbImage.h"
#define PI 3.141592654
#include <stdio.h>
#include <stdlib.h>
#include <GL\glut.h>


/////////   VARIÁVEIS GLOBAIS PARA OS ANGULOS////////////
float ang = 0;
float ang2 = 0;
float ang3 = 0;


void display();

class Membro
{
public:
	Membro(float a, float l) : largura(l), altura(a), conexao(0) {}
	void desenha();

	void setConexao(Membro *membro, float ang) { conexao = membro, angulo = ang; }

	void setAngulo(float ang) { angulo = ang; }
	float getAngulo() { return angulo; }

protected:
	float largura;
	float altura;

	float angulo;
	Membro *conexao;
};


void Membro::desenha()
{
	glPushMatrix();  //salva o contexto(1)

	glTranslatef(0.0, altura / 2.0, 0.0); //vai para o meio do osso

	glPushMatrix();   //salva o contexto(2)
	glScalef(largura, altura, largura);  //escala para o tamanho do osso

	glutSolidCube(largura);    //desenha o osso
	glPopMatrix();    //restaura o contexto(2)

	glTranslatef(0.0, altura / 2.0, 0.0); // vai para a ponta do osso

	glutSolidSphere(0.85*largura, 8, 8);        //desenha a bolinha

	if (conexao)
	{
		glRotatef(angulo, 1.0, 0.0, 0.0); //rotaciona para o angulo da conexcao
		conexao->desenha();              //desenha recursivamente
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
	a.setConexao(&b, 0.0);
	b.setConexao(&c, 0.0);
}

void Pata::setCurvatura(float curvatura)
{
	a.setAngulo(curvatura*0.9);
	b.setAngulo(curvatura*0.9);
}

///////////////////
class Torax
{
public:
	Torax(float grossura);
	void desenha();
	void setCurvatura(int dedo, float curv);
	float getCurvatura(int dedo) { return curvatura[dedo]; }
	void abrir(bool tudoJunto = false);
	void fechar(bool tudoJunto = false);
	//void tchau();
	//void fuck();
	//void hangloose();
	//void dedoDuro();
	//void positivo();
	//void vemProPau();
	//void home();
protected:
	float grossura;

	Pata mindinho;
	Pata anelar;
	Pata maior;
	Dedo indicador;

	Pata diantEsq1;
	Pata diantEsq2;
	Pata trazEsq1;
	Pata trazEsq2;
	Pata diantDir1;
	Pata diantDir2;
	Pata trazDir1;
	Pata trazDir2;
	float curvatura[5];
};

void Torax::desenha()
{
	glPushMatrix();
	glTranslatef(-2*grosssura, 0.0 , 0.0); 
	glPushMatrix();
	glTranslatef(0.0, -3 * grossura, 0.0);
	glRotatef(curvatura[0] * 0.9, 1.0, 0.0, 0.0);

	glRotatef(90, 0.0, 0.0, 1.0);
	glRotatef(50, 0.0, 1.0, 0.0);
	glRotatef(curvatura[4] * 0.5, 1.0, 0.0, 0.0);
	glScalef(1.5, 1, 1);


	mindinho.desenha();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.5*grossura, 0.0, 0.0);
	glutSolidSphere(grossura, 8, 8);
	glRotatef(curvatura[1] * 0.9, 1.0, 0.0, 0.0);
	anelar.desenha();
	glPopMatrix();
	glPushMatrix();
	glutSolidSphere(grossura, 8, 8);
	glRotatef(curvatura[2] * 0.9, 1.0, 0.0, 0.0);
	maior.desenha();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5*grossura, 0.0, 0.0);
	glutSolidSphere(grossura, 8, 8);
	glRotatef(curvatura[3] * 0.9, 1.0, 0.0, 0.0);
	indicador.desenha();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2 * grossura, -7 * grossura, 0.0);
	glRotatef(-80, 0.0, 0.0, 1.0);
	glRotatef(-20, 0.0, 1.0, 0.0);
	glRotatef(curvatura[4] * 0.5, 1.0, 0.0, 0.0);
	glScalef(1.5, 1, 1);
	glutSolidSphere(grossura, 8, 8);
	dedao.desenha();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.75*grossura, 3.0*grossura, 0.0);
	glScalef(5.5*grossura, 6.0*grossura, 1.25*grossura);
	glutSolidCube(1.0);
	glPopMatrix();
}

Torax t(0.6);


void init(void)
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LEQUAL);				// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
	glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
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

	glPushMatrix();

	glTranslatef(0.0, -5.0, -15.0);
	glRotatef(ang3, 0.0, 0.0, 1.0);
	glRotatef(ang, 0.0, 1.0, 0.0);
	glRotatef(ang2, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.8, 0);

	t.desenha();

	glPopMatrix();

	glutSwapBuffers();
}


void idle(){

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Scorpion");
	init();

	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}*/