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
		
#### 머테리얼 : 보여주기 위해 존재하는 포장지

### CPU vs GPU
	Material은 GPU에서 설정하는 거지만, Material Dynamic Instance의 코드를 수정하면...
	Material을 수정할 수 있다.
	PBR : Physics Based Rendering

#### Unreal에서의 Color 값
	원래는 RGBA 각 0~255까지 총 4바이트를 보내야 하는데, 실제로는 값을 줄 때 0 ~ 1 사이의 소수점 값으로 전달함. 그럼 자동 변환해 준다.
	float(4 Byte) 타입 사용
	
### Mesh
	Mesh도 그냥 클래스다. 근데 렌더를 도와주는...
	Component가 뭔데? 어떤 기능을 추가할 것인지를 명시. 
	블루프린트는 크래스고, Component는 클래스 안에 선언된 변수 같은 느낌.
	Component 클래스의 최상위 기반 클래스 :
		Actor Component : 어떠한 기능을 추가. (날라다니거나, 수영하거나...)
		Scene Component : 눈에 보임. 뷰포트에서 보임. 뷰포트에서 보이면 Scene Component
	StaticMesh