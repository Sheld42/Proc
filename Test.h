#include <iostream>
#include <fstream>
#include "FilesCmp.h"

using namespace std;


ball* InBall(ifstream &ifst);
void OutBall(ball &b, ofstream &ofst);
double Volume(ball &b);

class BallTest : public ::testing::Test{
};

TEST_F(BallTest, CheckVolume) {
	ball b;
	b.r = 1;
	b.d = 0;
	double expected = 4.18667;
	ASSERT_NEAR(expected, Volume(b), 0.01);
}

TEST_F(BallTest, CheckInput) {
	ifstream ifst("InBall.txt");
	ball* actual = InBall(ifst);
	ball b;
	b.r = 2;
	b.d = 3;
	
	ASSERT_EQ(actual->r, b.r);
	ASSERT_NEAR(actual->d, b.d, 0.01);
}

TEST_F(BallTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	ball b;
	b.r = 2;
	b.d = 3;
	OutBall(b, ofst);
	ofst.close();
	
	ifstream expected("OutBall.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

double Volume(parallelepiped &p);
parallelepiped* InParallelepiped(ifstream &ifst);
void OutParallelepiped(parallelepiped &p, ofstream &ofst);

class ParallelepipedTest : public ::testing::Test {
};

TEST_F(ParallelepipedTest, CheckVolume) {
	parallelepiped p;
	p.a = 1;
	p.b = 2;
	p.c = 3;
	p.d = 0;
	double expected = 6;
	ASSERT_EQ(expected, Volume(p));
}

TEST_F(ParallelepipedTest, CheckInput) {
	ifstream ifst("InParallelepiped.txt");
	parallelepiped* actual = InParallelepiped(ifst);
	parallelepiped p;
	p.a = 2;
	p.b = 2;
	p.c = 2;
	p.d = 3;
	
	ASSERT_EQ(actual->a, p.a);
	ASSERT_EQ(actual->b, p.b);
	ASSERT_EQ(actual->c, p.c);
	ASSERT_NEAR(actual->d, p.d, 0.01);
}

TEST_F(ParallelepipedTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	parallelepiped p;
	p.a = 2;
	p.b = 2;
	p.c = 2;
	p.d = 3;
	OutParallelepiped(p, ofst);
	ofst.close();
	
	ifstream expected("OutParallelepiped.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

double Volume(tetraedr &t);
tetraedr* InTetraedr(ifstream &ifst);
void OutTetraedr(tetraedr &t, ofstream &ofst);

class TetraedrTest : public ::testing::Test {
};

TEST_F(TetraedrTest, CheckVolume) {
	tetraedr t;
	t.a = 6;
	t.d = 0;
	double expected = 25.4558;
	ASSERT_NEAR(expected, Volume(t), 0.01);
}

TEST_F(TetraedrTest, CheckInput) {
	ifstream ifst("InTetraedr.txt");
	tetraedr* actual = InTetraedr(ifst);
	tetraedr t;
	t.a = 2;
	t.d = 3;
	
	ASSERT_EQ(actual->a, t.a);
	ASSERT_NEAR(actual->d, t.d, 0.01);
}

TEST_F(TetraedrTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	tetraedr t;
	t.a = 2;
	t.d = 3;
	OutTetraedr(t, ofst);
	ofst.close();
	
	ifstream expected("Outtetraedr.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

////##########################################################################################################
////##########################################################################################################

shape* In(ifstream &ifst);
bool Compare(shape *first, shape *second);
void Out(shape *s, ofstream &ofst);

class ShapeTest : public ::testing::Test {
};

TEST_F(ShapeTest, CheckInputBall) {
	ifstream ifst("ShapeInBall.txt");
	shape* actual = In(ifst);
	
	shape* expected;
	expected = new shape;
	expected->key = shape::type::BALL;
	expected->temperature = 4;
	
	ASSERT_TRUE(expected->key == actual->key);
	ASSERT_EQ(expected->temperature, actual->temperature);
}

TEST_F(ShapeTest, CheckInputParallelepiped) {
	ifstream ifst("ShapeInParallelepiped.txt");
	shape* actual = In(ifst);
	
	shape* expected;
	expected = new shape;
	expected->key = shape::type::PARALLELEPIPED;
	expected->temperature = 4;
	
	ASSERT_TRUE(expected->key == actual->key);
	ASSERT_EQ(expected->temperature, actual->temperature);
}

TEST_F(ShapeTest, CheckInputTetraedr) {
	ifstream ifst("ShapeInTetraedr.txt");
	shape* actual = In(ifst);
	
	shape* expected;
	expected = new shape;
	expected->key = shape::type::TETRAEDR;
	expected->temperature = 4;
	
	ASSERT_TRUE(expected->key == actual->key);
	ASSERT_EQ(expected->temperature, actual->temperature);
}

TEST_F(ShapeTest, CheckOutputBall) {
	ofstream ofst("ShapeOutTest.txt");
	
	shape* s;
	s = new shape;
	s->key = shape::type::BALL;
	ball *b;
	b = new ball;
	b->r = 2;
	b->d = 3;
	s->obj = (void*)b;
	s->temperature = 4;
	
	Out(s, ofst);
	ofst.close();
	
	ifstream expected("ShapeOutBall.txt");
	ifstream actual("ShapeOutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ShapeTest, CheckOutputParallelepiped) {
	ofstream ofst("ShapeOutTest.txt");
	
	shape* s;
	s = new shape;
	s->key = shape::type::PARALLELEPIPED;
	parallelepiped *p;
	p = new parallelepiped;
	p->a = 2;
	p->b = 2;
	p->c = 2;
	p->d = 3;
	s->obj = (void*)p;
	s->temperature = 4;
	
	Out(s, ofst);
	ofst.close();
	
	ifstream expected("ShapeOutParallelepiped.txt");
	ifstream actual("ShapeOutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ShapeTest, CheckOutputTetraedr) {
	ofstream ofst("ShapeOutTest.txt");
	
	shape* s;
	s = new shape;
	s->key = shape::type::TETRAEDR;
	tetraedr *t;
	t = new tetraedr;
	t->a = 2;
	t->d = 3;
	s->obj = (void*)t;
	s->temperature = 4;
	
	Out(s, ofst);
	ofst.close();
	
	ifstream expected("ShapeOutTetraedr.txt");
	ifstream actual("ShapeOutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ShapeTest, CheckCompare) {
	shape* s1;
	s1 = new shape;
	s1->key = shape::type::TETRAEDR;
	tetraedr *t1;
	t1 = new tetraedr;
	t1->a = 2;
	t1->d = 3;
	s1->obj = (void*)t1;
	s1->temperature = 4;
	
	shape* s2;
	s2 = new shape;
	s2->key = shape::type::TETRAEDR;
	tetraedr *t2;
	t2 = new tetraedr;
	t2->a = 3;
	t2->d = 3;
	s2->obj = (void*)t2;
	s2->temperature = 4;
	
	ASSERT_TRUE(Compare(s1, s2));
}

//#############################################################################################
//#############################################################################################

void Clear(container &c);
void In(container &c, ifstream &ifst);
void Init(container &c);
void Out(container &c, ofstream &ofst);
void OutBall(container &c, ofstream &ofst);
void OutParallelepiped(container &c, ofstream &ofst);
void OutTetraedr(container &c, ofstream &ofst);
void Sort(container &c);

class ContainerTest : public ::testing::Test {
};

TEST_F(ContainerTest, CheckInitContainer) {

	container c;
	Init(c);

	ASSERT_EQ(c.len, 0);
}

TEST_F(ContainerTest, CheckClearEmptyContainer) {

	container c;
	c.len = 0;
	Clear(c);

	ASSERT_EQ(c.len, 0);
}

TEST_F(ContainerTest, CheckClearContainer) {

	container c;
	c.len = 0;
	ball* b = new ball;
	c.cont[c.len] = (shape *)b;
	++c.len;
	Clear(c);

	ASSERT_EQ(c.len, 0);
}

TEST_F(ContainerTest, CheckOutBall) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	shape *s1 = new shape;
	s1->temperature = 4;

	s1->key = shape::type::BALL;
	ball* b = new ball;
	b->r = 2;
	b->d = 3;
	s1->obj = (void*)b;
	c.cont[c.len] = s1;
	++c.len;

	shape *s2 = new shape;
	s2->temperature = 4;

	s2->key = shape::type::PARALLELEPIPED;
	parallelepiped* p = new parallelepiped;
	p->a = 2;
	p->b = 2;
	p->c = 2;
	p->d = 3;
	s2->obj = (void*)p;
	c.cont[c.len] = s2;
	++c.len;

	shape *s3 = new shape;
	s3->temperature = 4;

	s3->key = shape::type::TETRAEDR;
	tetraedr* t = new tetraedr;
	t->a = 2;
	t->d = 3;
	s3->obj = (void*)t;
	c.cont[c.len] = s3;
	++c.len;

	OutBall(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutBall.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutParallelepiped) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	shape *s1 = new shape;
	s1->temperature = 4;

	s1->key = shape::type::BALL;
	ball* b = new ball;
	b->r = 2;
	b->d = 3;
	s1->obj = (void*)b;
	c.cont[c.len] = s1;
	++c.len;

	shape *s2 = new shape;
	s2->temperature = 4;

	s2->key = shape::type::PARALLELEPIPED;
	parallelepiped* p = new parallelepiped;
	p->a = 2;
	p->b = 2;
	p->c = 2;
	p->d = 3;
	s2->obj = (void*)p;
	c.cont[c.len] = s2;
	++c.len;

	shape *s3 = new shape;
	s3->temperature = 4;

	s3->key = shape::type::TETRAEDR;
	tetraedr* t = new tetraedr;
	t->a = 2;
	t->d = 3;
	s3->obj = (void*)t;
	c.cont[c.len] = s3;
	++c.len;

	OutParallelepiped(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutParallelepiped.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutTetraedr) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	shape *s1 = new shape;
	s1->temperature = 4;

	s1->key = shape::type::BALL;
	ball* b = new ball;
	b->r = 2;
	b->d = 3;
	s1->obj = (void*)b;
	c.cont[c.len] = s1;
	++c.len;

	shape *s2 = new shape;
	s2->temperature = 4;

	s2->key = shape::type::PARALLELEPIPED;
	parallelepiped* p = new parallelepiped;
	p->a = 2;
	p->b = 2;
	p->c = 2;
	p->d = 3;
	s2->obj = (void*)p;
	c.cont[c.len] = s2;
	++c.len;

	shape *s3 = new shape;
	s3->temperature = 4;

	s3->key = shape::type::TETRAEDR;
	tetraedr* t = new tetraedr;
	t->a = 2;
	t->d = 3;
	s3->obj = (void*)t;
	c.cont[c.len] = s3;
	++c.len;

	OutTetraedr(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutTetraedr.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSort) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	shape *s1 = new shape;
	s1->temperature = 4;

	s1->key = shape::type::BALL;
	ball* b = new ball;
	b->r = 2;
	b->d = 3;
	s1->obj = (void*)b;
	c.cont[c.len] = s1;
	++c.len;

	shape *s2 = new shape;
	s2->temperature = 4;

	s2->key = shape::type::PARALLELEPIPED;
	parallelepiped* p = new parallelepiped;
	p->a = 22;
	p->b = 2;
	p->c = 2;
	p->d = 3;
	s2->obj = (void*)p;
	c.cont[c.len] = s2;
	++c.len;

	shape *s3 = new shape;
	s3->temperature = 4;

	s3->key = shape::type::TETRAEDR;
	tetraedr* t = new tetraedr;
	t->a = 2;
	t->d = 3;
	s3->obj = (void*)t;
	c.cont[c.len] = s3;
	++c.len;

	Sort(c);
	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSort.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEmpty) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	Sort(c);
	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSortEmpty.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOut) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	shape *s1 = new shape;
	s1->temperature = 4;

	s1->key = shape::type::BALL;
	ball* b = new ball;
	b->r = 2;
	b->d = 3;
	s1->obj = (void*)b;
	c.cont[c.len] = s1;
	++c.len;

	shape *s2 = new shape;
	s2->temperature = 4;

	s2->key = shape::type::PARALLELEPIPED;
	parallelepiped* p = new parallelepiped;
	p->a = 22;
	p->b = 2;
	p->c = 2;
	p->d = 3;
	s2->obj = (void*)p;
	c.cont[c.len] = s2;
	++c.len;

	shape *s3 = new shape;
	s3->temperature = 4;

	s3->key = shape::type::TETRAEDR;
	tetraedr* t = new tetraedr;
	t->a = 2;
	t->d = 3;
	s3->obj = (void*)t;
	c.cont[c.len] = s3;
	++c.len;

	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOut.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}