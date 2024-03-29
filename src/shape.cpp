/*
    Name:        shape.cpp
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/10
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#include "gbl.h"
#include "shape.h"
#include "myframe_fb.h"
#include "myframe.h"
#include "obj_props.h"
#include "connect_props.h"
#include "var_props.h"


// ============================================================================
Shape::Shape( wxWindow      *parent,
              wxWindowID    id,
              const wxPoint &pos,
              const wxSize  &size,
              long          style)
      :wxScrolledWindow( parent, id, pos, size, style ) {}
//Shape::~Shape() {}
// ============================================================================


// ============================================================================
void Shape::OnLeftMouseDown( wxMouseEvent &event )
// ============================================================================
{
	Shape_Struct obj;

	pos = ScreenToClient( wxGetMousePosition() );

//printf( "Shape::OnLeftMouseDown\n" );
printf( "Shape::OnLeftMouseDown x=%d y=%d\n", pos.x, pos.y );

	switch( m_tool )
	{
		case NONE_TOOL:
printf( "m_tool(NONE_TOOL)=%d\n", m_tool );
			break;
		case ADD_TOOL:
			{
printf( "m_tool(ADD_TOOL)=%d\n", m_tool );
			}
			break;
		case FBD_TOOL:
			{
//printf( "m_tool(FBD_TOOL)=%d\n", m_tool );
//				if( m_fbd_tool->GetToolToggled( ID_FBD_CURSOR ) )
//				{
////printf( "ID_FBD_CURSOR\n" );
//				}
//				else
//				if( m_fbd_tool->GetToolToggled( ID_FBD_MOVE ) )
//				{
////printf( "ID_FBD_MOVE\n" );
//				}
//				else
				if( m_fbd_tool->GetToolToggled( ID_FBD_CMT ) )
				{
printf( "ID_FBD_CMT\n" );
				}
				else
				if( m_fbd_tool->GetToolToggled( ID_FBD_VAR ) )
				{
printf( "ID_FBD_VAR\n" );
					VarProps *dlg = new VarProps( this );
					dlg->SetTitle( wxT( "Variable properties" ) );
					dlg->m_choice->Append( wxT( "Input" ) );
					dlg->m_choice->Append( wxT( "Output" ) );
					dlg->m_choice->Append( wxT( "Input/Output" ) );
					dlg->m_choice->SetSelection( 0 );

dlg->arr_s.Clear();
dlg->arr_s.Add( wxT( "Var_1" ) );
dlg->arr_s.Add( wxT( "Var_2" ) );
dlg->arr_s.Add( wxT( "Var_3" ) );
dlg->arr_s.Add( wxT( "Var_4" ) );
//dlg->Preview();

					if( dlg->arr_s.Count() > 0 )
					{
						dlg->m_list->Set( dlg->arr_s );
					}

					dlg->ShowModal();

// ...

					delete dlg;
				}
				else
				if( m_fbd_tool->GetToolToggled( ID_FBD_FB ) )
				{
//printf( "ID_FBD_FB\n" );
					ObjProps *dlg = new ObjProps( this );
					dlg->SetTitle( wxT( "Block properties" ) );
					dlg->m_name->Disable();
					dlg->m_pou				= m_POU;
					dlg->IN_OUT_Decode_Ptr	= IN_OUT_Decode_Ptr;
					dlg->Shape_Ptr			= Shape_Ptr;
					dlg->Link_Point_Ptr		= Link_Point_Ptr;
					dlg->Block_ID			= block_id;
					dlg->Block_Name			= block_name;
					dlg->IN_OUT_Decode		= MyFrame::IN_OUT_Decode;
					dlg->Make_Obj			= MyFrame::Make_Obj;
					dlg->Fill_POU();
					dlg->m_button_ok->Show( false );

					dlg->ShowModal();

					if( dlg->ON_OK )
					{
//printf( "dlg->ON_OK x=%d y=%d\n", pos.x, pos.y );
						m_fbd_tool->ToggleTool( FBD_TOOL, false);
						m_fbd_tool->ToggleTool( ID_FBD_CURSOR, true );
// insert object to shape
					}
					delete dlg;
				}
				else
				if( m_fbd_tool->GetToolToggled( ID_FBD_CONNECT ) )
				{
printf( "ID_FBD_CONNECT\n" );
					ConnectProps *dlg = new ConnectProps( this );
					dlg->SetTitle( wxT( "Connect properties" ) );
					dlg->Block_ID	= block_id;
					dlg->Block_Name	= block_name;

					dlg->ShowModal();

					delete dlg;
				}
			}
			break;
		case LD_TOOL:
			{
printf( "m_tool(LD_TOOL)=%d\n", m_tool );
//				if( m_ld_tool->GetToolToggled( ID_LD_CURSOR ) )
//				{
//printf( "ID_LD_CURSOR\n" );
//				}
//				else
//				if( m_ld_tool->GetToolToggled( ID_LD_MOVE ) )
//				{
////printf( "ID_LD_MOVE\n" );
//				}
//				else
				if( m_ld_tool->GetToolToggled( ID_LD_CMT ) )
				{
printf( "ID_LD_CMT\n" );
				}
				else
				if( m_ld_tool->GetToolToggled( ID_LD_VAR ) )
				{
printf( "ID_LD_VAR\n" );
					VarProps *dlg = new VarProps( this );
					dlg->SetTitle( wxT( "Variable properties" ) );

					dlg->ShowModal();

// ...

					delete dlg;
				}
//				else
//				if( m_ld_tool->GetToolToggled( ID_FBD_MOVE ) )
//				{
////printf( "ID_LD_MOVE\n" );
//				}
				else
				if( m_ld_tool->GetToolToggled( ID_LD_FB ) )
				{
//printf( "ID_LD_FB\n" );
					ObjProps *dlg = new ObjProps( this );
					dlg->SetTitle( wxT( "Block properties" ) );
					dlg->m_name->Disable();
					dlg->m_pou				= m_POU;
					dlg->IN_OUT_Decode_Ptr	= IN_OUT_Decode_Ptr;
					dlg->Shape_Ptr			= Shape_Ptr;
					dlg->Link_Point_Ptr		= Link_Point_Ptr;
					dlg->Block_ID			= block_id;
					dlg->Block_Name			= block_name;
					dlg->IN_OUT_Decode		= MyFrame::IN_OUT_Decode;
					dlg->Make_Obj			= MyFrame::Make_Obj;
					dlg->Fill_POU();
					dlg->m_button_ok->Show( false );

					dlg->ShowModal();

					if( dlg->ON_OK )
					{
//printf( "dlg->ON_OK x=%d y=%d\n", pos.x, pos.y );
						m_ld_tool->ToggleTool( FBD_TOOL, false);
						m_ld_tool->ToggleTool( ID_FBD_CURSOR, true );
// insert object to shape
					}
					delete dlg;
				}
				else
				if( m_ld_tool->GetToolToggled( ID_LD_CONNECT ) )
				{
printf( "ID_LD_CONNECT\n" );
					ConnectProps *dlg = new ConnectProps( this );
					dlg->SetTitle( wxT( "Connect properties" ) );
					dlg->Block_ID	= block_id;
					dlg->Block_Name	= block_name;

					dlg->ShowModal();

					delete dlg;
				}
			}
			break;
	}

//start_pos = ScreenToClient( wxGetMousePosition() );
//CaptureMouse();
    event.Skip();
}
// ============================================================================


// ============================================================================
void Shape::OnRightMouseDown(wxMouseEvent &event)
// ============================================================================
{
printf( "Shape::OnRightMouseDown\n" );
	event.Skip();
}
// ============================================================================


// ============================================================================
void Shape::OnLeftMouseUp( wxMouseEvent &event )
// ============================================================================
{
//Shape_Struct obj;
//wxPoint pos = ScreenToClient( wxGetMousePosition() );

//printf( "Shape::OnLeftMouseUp x=%d y=%d\n", pos.x, pos.y );

//    if( GetCapture() == this )
//    {
//
//obj.p1 = start_pos;
//obj.p2 = end_pos;
//obj.Block_ID = block_id;
//shape_obj.push_back(obj);
//
//        ReleaseMouse();
//    }
    //else
    //{}
    event.Skip();
}
// ============================================================================


// ============================================================================
void Shape::OnLeftMouseDClick( wxMouseEvent &event )
// ============================================================================
{
printf( "Shape::OnLeftMouseDClick\n" );
	event.Skip();
}
// ============================================================================


// ============================================================================
void Shape::OnMotion( wxMouseEvent &event )
// ============================================================================
{
//wxPoint pos = ScreenToClient( wxGetMousePosition() );
//printf( "Shape::OnMotion x=%d y=%d\n", pos.x, pos.y );

//    if( GetCapture() == this )
//    {
        end_pos = ScreenToClient( wxGetMousePosition() );
// ToDO ...
        Refresh();
//    }
	event.Skip();
}
// ============================================================================


// ============================================================================
void Shape::OnMouseWheel( wxMouseEvent &event )
// ============================================================================
{
//printf( "Shape::OnMouseWheel\n" );

//wxPoint pt( event.GetPosition() );
//int x,y;
//CalcUnscrolledPosition( pt.x, pt.y, &x, &y );
//printf( "Mouse wheel event at: %d %d, scrolled: %d %d\n"
		//"Rotation: %d, delta: %d, inverted: %d\n",
		//pt.x, pt.y, x, y,
		//event.GetWheelRotation(), event.GetWheelDelta(),
		//event.IsWheelInverted() );

//printf( "Mouse wheel: %d\n", event.GetWheelRotation() );

//if( event.GetWheelRotation() > 0 )
//printf( "Mouse wheel UP\n" );
//else
//printf( "Mouse wheel DOWN\n" );

event.Skip();
}
// ============================================================================


// ============================================================================
void Shape::OnMiddleDown( wxMouseEvent &event )
// ============================================================================
{
pos = ScreenToClient( wxGetMousePosition() );
printf( "Shape::OnMiddleDown x=%d y=%d\n", pos.x, pos.y );

//printf( "GetToolToggled(ID_FBD_CURSOR)=%d\n", m_fbd_tool->GetToolToggled( ID_FBD_CURSOR ) );
//printf( "GetToolToggled(ID_FBD_MOVE)=%d\n", m_fbd_tool->GetToolToggled( ID_FBD_MOVE ) );
// ToDO ...
//	Refresh();

	event.Skip();
}
// ============================================================================


// ============================================================================
void Shape::OnEraseBackground( wxEraseEvent &WXUNUSED( event ) )
// ============================================================================
{
    if( GetCapture() == this )
    {
        Refresh();
    }
}
// ============================================================================

//// ============================================================================
//void Shape::PaintObj( wxDC *dc )
//// ============================================================================
//{
////dc->DrawLine( 10, 10, 200, 200 );
//}
//// ============================================================================


// ============================================================================
void Shape::OnPaint( wxPaintEvent &WXUNUSED( event ) )
// ============================================================================
{
	//int font_size = FONT_SIZE;
	wxSize sz;

	wxBufferedPaintDC dc( this );
	PrepareDC( dc );

//wxRect rect;

wxFont font = wxFont( FONT_SIZE, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString );
p_pen.SetColour( 0, 0, 0 );
p_pen.SetWidth( 1 );

dc.SetPen( p_pen );
dc.SetBackground( wxBrush( GetBackgroundColour() ) );
dc.SetFont( font );
dc.Clear();

//<<//dc.SetUserScale( 0.5, 0.5 );

//dc.DrawLabel( wxString::Format( wxT("%i,%i"), end_pos.x, end_pos.y ), wxNullBitmap, GetClientRect(), wxALIGN_CENTER );

//<<dc.DrawLabel( wxString::Format( wxT("%i,%i"), end_pos.x, end_pos.y ), rect = GetClientRect(), wxALIGN_CENTER );

dc.DrawLabel( wxString::Format( wxT("%i,%i"), end_pos.x, end_pos.y ), GetClientRect(), wxALIGN_CENTER );
//dc.DrawLine( 10, 10, 200, 200 );

//PaintObj( &dc );

//<<//printf( "rect x=%d y=%d\n", rect.width, rect.height );

//sz = dc.GetTextExtent( wxString::Format( wxT("%i,%i"), end_pos.x, end_pos.y ) );
//printf( "w=%d h=%d\n", sz.GetWidth(), sz.GetHeight() );

//sz = dc.GetTextExtent( wxString::Format( wxT("W") ) );
//printf( "w=%d h=%d\n", sz.GetWidth(), sz.GetHeight() );


//<<	// Draw for test
//<<	if( GetCapture() == this )
//<<	{
//<<		dc.DrawLine(start_pos, end_pos);
//<<	}
//<<
//<<	int i, n;
//<<	n = shape_obj.size();
//<<	for( i = 0; i < n; i++ )
//<<	{
//<<		if( shape_obj[i].Block_ID == block_id )
//<<		{
//<<			dc.DrawLine( shape_obj[i].p1, shape_obj[i].p2 );
//<<		}
//<<	}


}
// ============================================================================


// ============================================================================
void Shape::OnShapeEnter( wxMouseEvent &event )
// ============================================================================
{
//printf("Shape::OnShapeEnter\n");

	event.Skip();
}
// ============================================================================


// ============================================================================
void Shape::OnShapeLeave( wxMouseEvent &event )
// ============================================================================
{
//printf("Shape::OnShapeLeave\n");

	event.Skip();
}
// ============================================================================


// ============================================================================
void Shape::OnChar( wxKeyEvent &event )
// ============================================================================
{
    wxUint32 key;

    key = event.GetKeyCode();
	//if( event.m_altDown )
	//{
		//ALT_KEY = true;
	//}
	//else
	//if( event.m_controlDown )
	//{
		//CTRL_KEY = true;
	//}
	//else
	//if( event.m_shiftDown )
	//{
		//SHIFT_KEY = true;
	//}

	if( key == 0x0132 )
	{
		SHIFT_KEY = true;
	}
	//else
	if( key == 0x0133 )
	{
		ALT_KEY = true;
	}
	//else
	if( key == 0x0134 )
	{
		CTRL_KEY = true;
	}

//printf( "Shape::OnChar ALT=%d CTRL=%d SHIFT=%d\n", ALT_KEY, CTRL_KEY, SHIFT_KEY );

	if( ALT_KEY && ( key == 0x0157 ) ) // Alt + F4
	{
		Close();
	}

	event.Skip();
}
// ============================================================================


// ============================================================================
void Shape::OnKeyUp( wxKeyEvent &event )
// ============================================================================
{
    wxUint32 key;

    key = event.GetKeyCode();
	if( key == 0x0132 )
	{
		SHIFT_KEY = false;
	}
	//else
	if( key == 0x0133 )
	{
		ALT_KEY = false;
	}
	//else
	if( key == 0x0134 )
	{
		CTRL_KEY = false;
	}

printf( "Shape::OnKeyUp ALT=%d CTRL=%d SHIFT=%d\n", ALT_KEY, CTRL_KEY, SHIFT_KEY );

	event.Skip();
}
// ============================================================================


BEGIN_EVENT_TABLE( Shape, wxScrolledWindow )
	EVT_PAINT(            Shape::OnPaint )
	EVT_ERASE_BACKGROUND( Shape::OnEraseBackground )
	EVT_MOTION(           Shape::OnMotion )
	EVT_MOUSEWHEEL(       Shape::OnMouseWheel )
	EVT_LEFT_DOWN(        Shape::OnLeftMouseDown )
	EVT_LEFT_UP(          Shape::OnLeftMouseUp )
	EVT_LEFT_DCLICK(      OnLeftMouseDClick )
	EVT_RIGHT_DOWN(       OnRightMouseDown )
	EVT_MIDDLE_DOWN(      Shape::OnMiddleDown )
	EVT_ENTER_WINDOW(     Shape::OnShapeEnter )
	EVT_LEAVE_WINDOW(     Shape::OnShapeLeave )
	EVT_CHAR_HOOK(        Shape::OnChar )
	EVT_KEY_UP(           Shape::OnKeyUp )
END_EVENT_TABLE()
