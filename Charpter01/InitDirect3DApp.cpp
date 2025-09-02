// Demonstrates the sample framework by initializing Direct3D, clearing 
// the screen, and displaying frame stats.
//
//***************************************************************************************

#include "../Common/d3dApp.h"
#include <DirectXColors.h>

using namespace DirectX;

class InitDirect3DAPP : public D3DApp
{
public:
    InitDirect3DAPP(HINSTANCE hInstance);
    ~InitDirect3DAPP();

    virtual bool Initialize() override;

private:
    virtual void OnResize() override;
    virtual void Update(const GameTimer& gt) override;
    virtual void Draw(const GameTimer& gt) override;
};

/**
 * 
 * @param hInstance 当前进程（应用程序实例）的句柄
 * @param prevInstance 现状（Win32/Win64）：始终为 NULL，系统不再使用它。你可以完全忽略，不会影响功能。
 * @param cmdLine 命令行参数，一段“原样的参数文本”（char*，不含程序名，需你自己切）。比如命令行是：MyApp.exe -w 800 -h 600。pCmdLine 里就是："-w 800 -h 600"（整段文字）
 * @param showCmd 窗口初始显示方式。常见值：SW_SHOW、SW_SHOWNORMAL、SW_MINIMIZE、SW_SHOWMAXIMIZED
 * @return 返回值
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR cmdLine, int showCmd)
{
// 只在调试版本生效（DEBUG 或 _DEBUG）。
#if defined(DEBUG) | defined(_DEBUG)
    // _CRTDBG_ALLOC_MEM_DF 跟踪每次堆内存分配，便于调试。
    // _CRTDBG_LEAK_CHECK_DF 程序退出时自动检测并在输出窗口报告内存泄漏
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    try
    {
        InitDirect3DAPP theApp(hInstance);  // 创建一个实例
        if (!theApp.Initialize())
            return 0;

        return theApp.Run();
    }
    catch (DxException& e)
    {
        MessageBox(nullptr, e.ToString().c_str(), L"HR Failed", MB_OK);
        return 0;
    }
}

InitDirect3DAPP::InitDirect3DAPP(HINSTANCE hInstance) : D3DApp(hInstance)
{
}

InitDirect3DAPP::~InitDirect3DAPP()
{
}

bool InitDirect3DAPP::Initialize()
{
    if (!D3DApp::Initialize())
        return false;

    return true;
}

void InitDirect3DAPP::OnResize()
{
    D3DApp::OnResize();
}

void InitDirect3DAPP::Update(const GameTimer& gt)
{
    
}

void InitDirect3DAPP::Draw(const GameTimer& gt)
{
    // Reuse the memory associated with command recording.
    // We can only reset when the associated command lists have finished execution on the GPU.
	ThrowIfFailed(mDirectCmdListAlloc->Reset());

	// A command list can be reset after it has been added to the command queue via ExecuteCommandList.
    // Reusing the command list reuses memory.
    ThrowIfFailed(mCommandList->Reset(mDirectCmdListAlloc.Get(), nullptr));

	// Indicate a state transition on the resource usage.
	mCommandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(CurrentBackBuffer(),
		D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET));
    
}



