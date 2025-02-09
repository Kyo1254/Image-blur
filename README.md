### Image Blur test

1. 프로젝트 구조
  - Opencvdll : Opencv 4.7.0 를 사용한 Blur 함수를 포함하는 dll 프로젝트
  - Customdll : Oepncv를 사용하지 않고, 구현한 ImageObject와 Blur 함수를 포함하는 dll 프로젝트
  - ImageObject : 각 프로젝트에서 사용하기 위한 ImageObject 클래스를 포함하는 프로젝트
  - MainProject : 프로그램에 필요한 설정 파일을 읽고, 각 dll의 기능들을 실행하는 MFC 프로젝트
    
2. 테스트 결과
   - MainProject (MFC 프로젝트)에 dll load를 실패하여 제시된 테스트를 진행하지 못했습니다.
   - 기존 진행해왔던 업무들은 주로 C# 기반의 GUI 프로그램과 C++ 실행파일 형식으로 수행하여, dll에 대한 활용도가 부족하였던 듯 합니다.
   - 추가로 기회가 주어진다면 해결할 수 있도록 노력하겠습니다.
