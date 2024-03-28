# A course registration program
> **QT 학습을 위해 C++ 코드를 단순 CMD가 아닌 QT GUI를 구성해보기**

<div align="center">
<img width="143" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/0df882ea-1a59-4625-98bf-c8f8dcac3fa1">
<div align="left">

---

## 프로젝트 소개
> 로그인 기능을 통해 **보안성**을 높이고 인증코드를 통해 무분별한 회원가입 방지

> 수강신청의 기본인 강의 **신청, 철회, 등록, 삭제**를 구현

> 학생은 **비밀번호 변경** 기능을 추가

## Stacks 🐈

### Environment
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=Git&logoColor=white)
![Github](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=GitHub&logoColor=white)

### Data Base
![SQLITE](https://img.shields.io/badge/mysql-4479A1?style=for-the-badge&logo=mysql&logoColor=white)

### Development
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Qt](https://img.shields.io/badge/QT-41CD52?style=for-the-badge&logo=qt&logoColor=white)

---
## 화면 구성 📺
<div align="center">

| 로그인 | 회원가입 |
| :------------: | :------------: |
| <img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/9dc96a8c-9628-472e-b4d9-1963ae5b10c9"> |<img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/654d9d1b-8ecc-4b5e-acec-594822602d1f"> |
| 회원가입 진행 1 | 회원가입 진행 2 |
| <img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/758aaa5f-d7ed-4839-b44d-3be8bd6e3ced"> |<img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/03ca89b1-e981-4670-88a2-ef6ea1891d48"> |
| 학생 메뉴 1 | 학생 메뉴 2 |
| <img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/19c0221c-7dcd-41fe-a318-64f39530b1c7"> |<img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/82bb0314-d35c-437e-8a38-ba80cb5fcad6"> |
| 비밀번호 변경 1 | 비밀번호 변경 2 |
| <img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/480d13b3-6617-4615-bcde-726776147f9f"> |<img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/8d9ef16d-fc60-4b99-9733-48c7fe38bfcb"> |
| 관리자 메뉴 1 | 관리자 메뉴 2 |
| <img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/e7fdaef9-3a80-4ff1-954c-88ac52f24adc"> |<img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/953b06d3-10ee-4cb0-82a6-f7ce9f350ac0"> |

<div align="left">
  
## 에러 시 📺
<div align="center">
  
| QtSql 라이브러리 위치 | 라이브러리 연결 |
| :------------: | :------------: |
| <img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/ffb93249-2bcf-4517-a427-afc0e1c91ac5"> | <img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/1c2df7f8-2ddb-4708-924e-772056b43ed8"> |
| 인코딩 관련 에러 해결 | 인코딩 관련 에러 해결 |
| <img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/880c29a7-7121-4aa8-9b73-1524d13d9e6d">|<img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/f6b9503f-9fcb-49bf-b5a1-4cceb2a2dccf"> |
| 인코딩 관련 에러 해결 | 인코딩 관련 에러 해결 |
| <img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/4457aa33-d730-48a3-a781-b35114615beb"> |<img width="425" alt="image" src="https://github.com/ansejoon00/Cpp_A_course_registration_program_QT.ver/assets/156414896/6d89d1c7-9c4f-4685-9918-8af81ca48fe6"> |

<div align="left">

---
## 아키텍처

### 디렉터리 구조
```bash
├── Source Files
│   ├── main.cpp
│   ├── Login.cpp
│   ├── Signup.cpp
│   ├── Student_Menu.cpp
│   ├── Change_PW.cpp
│   └── Admin_Menu.cpp
│       
├── Header Files
│   ├── Login.h
│   ├── Signup.h
│   ├── Student_Menu.h
│   ├── Change_PW.h
│   └── Admin_Menu.h
│
└── Form Files
    ├── Login.ui
    ├── Signup.ui
    ├── Student_Menu.ui
    ├── Change_PW.ui
    ├── Admin_Menu.ui
    ├── ui_Login.h
    ├── ui_Signup.h
    ├── ui_Student_Menu.h
    ├── ui_Change_PW.h
    └── ui_Admin_Menu.h
