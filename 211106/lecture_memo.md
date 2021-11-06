#### 언리얼에 있는 모든 오브젝트는 UObject 클래스를 상속받는다

#### 그런데 월드에 배치된 것을 Actor라고 하고, 이때 이런 배치되는 물체는 Actor를 상속받는다.

#### 에셋 유형 Map -> 그냥 Level로 부르고 취급하자.

### 언리얼 프로젝트 Tree :
	Config : 환경설정
	Content : 에셋 등등
	DerivedDataCache / Intermediate / Saved : 컴파일된 파일들, 로그들 저장. 삭제해도 상관없음
	
### 트랜스폼
	위치 : Location (x, y, z)
	회전 : Rotation (roll, pitch, yaw)
	스케일 : Scale (배율)
	
	
### 블루프린트
	이벤트그래프 : 
		BeginPlay : 게임이 시작할 때 어떻게 해 줄건지
		ActorBeginOverlap : 어떤 액터랑 겹쳤을 때 호출
		Tick : 계속 호출해줌