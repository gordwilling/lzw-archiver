#ifndef OPEN_PNG_H
#define OPEN_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char open_png[] = 
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x10, 
	0x00, 0x00, 0x00, 0x10, 0x08, 0x06, 0x00, 0x00, 0x00, 0x1F, 
	0xF3, 0xFF, 0x61, 0x00, 0x00, 0x02, 0x8D, 0x49, 0x44, 0x41, 
	0x54, 0x38, 0x8D, 0x6D, 0x93, 0x39, 0x68, 0x54, 0x51, 0x14, 
	0x86, 0xBF, 0xF7, 0x9C, 0xB8, 0x84, 0xC4, 0xCC, 0x68, 0x40, 
	0xDC, 0x0D, 0x56, 0x2A, 0xB8, 0x81, 0xDA, 0x08, 0x46, 0xB1, 
	0x53, 0x41, 0xB0, 0xB5, 0x10, 0x6D, 0x2C, 0x04, 0x27, 0xA0, 
	0x60, 0xE3, 0x52, 0xA8, 0x8D, 0x8A, 0x82, 0x58, 0x9A, 0xD8, 
	0x08, 0x9A, 0x4A, 0x50, 0x2C, 0x35, 0x28, 0x28, 0xEE, 0x71, 
	0x4D, 0x34, 0x92, 0xB8, 0x04, 0x35, 0x4E, 0x66, 0xF2, 0x66, 
	0x9F, 0x79, 0xEF, 0x9E, 0x73, 0x2C, 0x26, 0x19, 0xE3, 0xF2, 
	0x37, 0xB7, 0xB8, 0xF7, 0x7C, 0xFC, 0xE7, 0xFE, 0xE7, 0x78, 
	0x8F, 0xBA, 0x77, 0xBF, 0x00, 0x56, 0xC7, 0xA6, 0xF8, 0xC4, 
	0x62, 0x3E, 0xB1, 0x29, 0x1E, 0x9E, 0xE7, 0x31, 0x59, 0xBE, 
	0xEF, 0x01, 0x04, 0x22, 0xD6, 0xB1, 0x62, 0x7B, 0xE7, 0x95, 
	0xC9, 0x77, 0x31, 0x60, 0xF5, 0xFA, 0x6D, 0x2B, 0x49, 0x0D, 
	0x67, 0x08, 0x7E, 0xE4, 0x18, 0x1B, 0xC9, 0x91, 0x98, 0xBF, 
	0x94, 0xD6, 0xC5, 0xCB, 0x49, 0xCC, 0x5F, 0x5A, 0x7F, 0x58, 
	0xC9, 0x8D, 0xC6, 0x3F, 0xDE, 0xBB, 0x7E, 0x1E, 0xF8, 0x07, 
	0x80, 0x9A, 0x31, 0x7B, 0x5E, 0x82, 0xD9, 0xF3, 0x12, 0xB8, 
	0x48, 0x08, 0x46, 0x72, 0x0C, 0x3C, 0xB8, 0xC9, 0xFA, 0x75, 
	0xAB, 0x60, 0xDC, 0xCC, 0xF4, 0x96, 0x25, 0x0C, 0x49, 0x36, 
	0xBE, 0xEC, 0x6A, 0xAB, 0xB9, 0x8A, 0x5E, 0x18, 0xD8, 0x97, 
	0xE9, 0x00, 0xF0, 0x01, 0x4C, 0x0C, 0x53, 0x43, 0xC5, 0xF0, 
	0x7D, 0x8F, 0x59, 0x73, 0x5B, 0x00, 0x08, 0xB3, 0xDF, 0xD1, 
	0xFC, 0x08, 0x14, 0x7F, 0xC2, 0xB7, 0xC7, 0xA8, 0x18, 0x51, 
	0xA4, 0x94, 0x3C, 0x97, 0x5C, 0x74, 0xA1, 0xE5, 0x6E, 0x1D, 
	0xA0, 0x62, 0x88, 0x28, 0x2A, 0x8A, 0x4A, 0x0D, 0x04, 0xE0, 
	0x9C, 0x12, 0x39, 0xAD, 0xDB, 0x5D, 0xE4, 0x35, 0xA3, 0x15, 
	0xDB, 0x2C, 0x4E, 0x29, 0x34, 0x84, 0xED, 0x73, 0x4E, 0x36, 
	0x9D, 0x18, 0x07, 0x28, 0xEA, 0x6A, 0x85, 0xEA, 0x0C, 0x71, 
	0x35, 0x40, 0x24, 0x86, 0xA8, 0xD2, 0x5F, 0xCE, 0xB0, 0xA3, 
	0xFF, 0x36, 0xC7, 0x4B, 0xCF, 0x18, 0xDC, 0x3F, 0xD6, 0x43, 
	0x99, 0x1B, 0xE5, 0x19, 0x8E, 0xD0, 0xB9, 0x83, 0x75, 0x07, 
	0x35, 0x88, 0xD6, 0x9D, 0x00, 0x84, 0x91, 0xF0, 0xAE, 0x98, 
	0x61, 0xFF, 0xD0, 0x3D, 0xF6, 0xB6, 0x1F, 0x43, 0x1A, 0x5B, 
	0x01, 0xB0, 0xA2, 0xC5, 0x01, 0x22, 0xD3, 0x78, 0x0C, 0x40, 
	0x9C, 0x82, 0x81, 0x01, 0x98, 0xD5, 0x4E, 0xE0, 0x6D, 0x31, 
	0xCD, 0x25, 0x19, 0x26, 0xB9, 0xE5, 0x14, 0x3D, 0x5F, 0x6F, 
	0xD1, 0xF7, 0xFD, 0x25, 0x73, 0x4E, 0x36, 0x75, 0xC9, 0x0C, 
	0x6D, 0x07, 0xD0, 0xC8, 0xC6, 0x53, 0x10, 0xC3, 0xCC, 0x30, 
	0x05, 0x30, 0xCC, 0xE0, 0x0B, 0x79, 0xAE, 0x69, 0x86, 0x03, 
	0x9B, 0x8E, 0x72, 0xBD, 0xEF, 0x22, 0x2F, 0x47, 0x5E, 0x60, 
	0x0A, 0xB1, 0x84, 0xB7, 0x47, 0x67, 0x02, 0x11, 0xC8, 0x04, 
	0x40, 0x9C, 0x62, 0x5A, 0xB3, 0x60, 0x06, 0xD5, 0x72, 0x95, 
	0xCB, 0xD3, 0x3E, 0x73, 0x64, 0xD3, 0x19, 0xBA, 0xDF, 0x9D, 
	0x63, 0x70, 0x6C, 0x00, 0x80, 0xE6, 0x05, 0x53, 0x29, 0x84, 
	0x21, 0x61, 0x28, 0x78, 0x55, 0x20, 0xB0, 0x9E, 0x9A, 0x03, 
	0xA7, 0x98, 0x82, 0x99, 0x31, 0xF4, 0xE6, 0x13, 0x66, 0xE0, 
	0x7C, 0xE3, 0xDA, 0xAB, 0xB3, 0xA4, 0xAA, 0x5F, 0xF8, 0x5B, 
	0xE6, 0x40, 0xDE, 0x5B, 0x20, 0x62, 0x1D, 0x7F, 0xC4, 0x28, 
	0xE3, 0x91, 0x65, 0x72, 0xCA, 0xAE, 0xF4, 0x42, 0xDE, 0x3E, 
	0xEF, 0xA7, 0x50, 0x0C, 0xEB, 0x85, 0xAE, 0xA2, 0x14, 0x3F, 
	0x47, 0x14, 0x9E, 0x86, 0x9F, 0x34, 0xAF, 0x9B, 0x5D, 0xA7, 
	0xF6, 0xFA, 0x13, 0x2D, 0xA8, 0xFB, 0x0D, 0x08, 0x23, 0x21, 
	0x51, 0x69, 0xE4, 0x70, 0xE3, 0x46, 0x4A, 0x1F, 0x1C, 0xC5, 
	0x42, 0x04, 0x40, 0xAA, 0xAF, 0xC4, 0xC1, 0x86, 0xB5, 0x54, 
	0x2E, 0xB9, 0xB6, 0xE8, 0xB2, 0xF6, 0x4E, 0x0C, 0x52, 0x10, 
	0xA4, 0xB2, 0x88, 0xAB, 0xCD, 0x00, 0x40, 0x90, 0xCD, 0x91, 
	0x1A, 0x4D, 0x53, 0x19, 0xCB, 0x73, 0xA8, 0x69, 0x2D, 0x95, 
	0xD7, 0x21, 0xE5, 0x9C, 0x43, 0x9D, 0xB1, 0x21, 0x3E, 0x77, 
	0xCD, 0xDF, 0xBB, 0xD0, 0x96, 0x4B, 0x67, 0xBB, 0xCA, 0xF9, 
	0xD2, 0xCE, 0xE6, 0x44, 0x9C, 0x58, 0x43, 0x03, 0x6F, 0x06, 
	0x46, 0x93, 0x67, 0x3B, 0x9F, 0xDC, 0x04, 0x06, 0x01, 0x9A, 
	0x92, 0x53, 0xE3, 0x72, 0x5F, 0xBB, 0xA4, 0x6A, 0xC1, 0xD6, 
	0xD3, 0xDD, 0xBD, 0x93, 0x01, 0xF5, 0xBD, 0x7D, 0xD4, 0xBD, 
	0x7B, 0x27, 0xD0, 0x05, 0xC4, 0x1F, 0xF6, 0x7E, 0x5B, 0x99, 
	0x3C, 0x7D, 0xE7, 0xF5, 0x3F, 0xBF, 0xF7, 0x1F, 0xFD, 0x02, 
	0xC7, 0x2E, 0x9A, 0xD5, 0xA1, 0x77, 0xEF, 0x1D, 0x00, 0x00, 
	0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
};

wxBitmap& open_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( open_png, sizeof( open_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
};


#endif //OPEN_PNG_H