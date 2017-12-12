# Compiler Assembler Linker
### Compilation
- 한 언어로 씌여진 프로그램을 읽고 이를 다른 언어로 번역하는 과정
- 일반적으로, 고급 언어로 씌여진 프로그램을 기계어로 번역

![compilation](http://www.tenouk.com/ModuleW_files/ccompilerlinker001.png)

출처: http://www.tenouk.com/ModuleW.html

### Preprocessor
- 해시태그가 없는, 순수한 소스코드로 파일을 변경
    - Inclusion: 해당 위치에 추가하고자 하는 파일의 코드를 추가
    - Macros: 매크로 설정된 코드를 전부 약속된 매크로 파일로 변경
    - Conditional compilation: 컴파일이 필요없는 코드 부분을 삭제
    - Other compiler directives: ex) `#pragma once`

### Compiler
- 분석
- Lexical Analysis
	- 왼쪽에서 오른쪽으로 소스를 읽음
	- 입력자료의 어휘를 인식, 토큰으로 분리
	- 토큰: 문법 카테고리로 인식
		- 토큰: 어휘의 타입, 값
		- 영어에서: 명사, 동사, 형용사 등
		- 프로그래밍 언어에서: Identifier, Integer, keyword...

![Lexical Analysis](http://img.c4learn.com/2012/01/Concept-of-Lexical-Analyzer-in-Compiler-Design.gif)

출처: http://www.c4learn.com/c-programming/lexical-analysis-phases/

- Syntactic Analysis
	- 분해한 토큰을 이용, 트리 형태를 만듦

![Syntax tree](http://www.pling.org.uk/cs/lsaimg/parsetreetosyntaxtree.png)

출처: http://www.pling.org.uk/cs/lsa.html

- Semantic Anaysis
 	- 코드의 의미를 파악: 타입이 맞는지, Scope를 제대로 사용했는지
 	- Symbol table 생성

- Intermediate code 생성
    - 만들어진 parse tree를 컴파일러 각자의 코드로 변경
    - 이때 최적화를 통해 코드의 크기를 줄이고 효율적으로 변경
    - 어셈블리와 비슷
- Code Generation

