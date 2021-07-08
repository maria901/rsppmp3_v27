   
/*
    <C# Sample Project for rsppmp3>    
    Copyright (C) <2020>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
	and GNU LESSER GENERAL PUBLIC LICENSE along with this program.  
	If not, see <http://www.gnu.org/licenses/>.
    
    support: http://nomade.sourceforge.net
    
	direct programmers e-mails:
	Ricardo: arsoftware25@gmail.com
	Amanda : arsoftware10@gmail.com
	
	immediate contact(for a very fast answer) WhatsApp
	(+55)41 9627 1708 - it is always on
*/

using System;
using System.Collections;
using System.Windows.Forms;

namespace mp3dll
{
	/// <summary>
	/// Description of Class1.
	/// </summary>
	/// <summary>
	/// This class is an implementation of the 'IComparer' interface.
	/// </summary>
	public class ListViewColumnSorter : IComparer
	{
		/// <summary>
		/// Specifies the column to be sorted
		/// </summary>
		private int ColumnToSort;
		/// <summary>
		/// Specifies the order in which to sort (i.e. 'Ascending').
		/// </summary>
		private SortOrder OrderOfSort;
		/// <summary>
		/// Case insensitive comparer object
		/// </summary>
		private CaseInsensitiveComparer ObjectCompare;

		/// <summary>
		/// Class constructor.  Initializes various elements
		/// </summary>
		public ListViewColumnSorter()
		{
			// Initialize the column to '0'
			ColumnToSort = 0;

			// Initialize the sort order to 'none'
			OrderOfSort = SortOrder.None;

			// Initialize the CaseInsensitiveComparer object
			ObjectCompare = new CaseInsensitiveComparer();
		}

		/// <summary>
		/// This method is inherited from the IComparer interface.  It compares the two objects passed using a case insensitive comparison.
		/// </summary>
		/// <param name="x">First object to be compared</param>
		/// <param name="y">Second object to be compared</param>
		/// <returns>The result of the comparison. "0" if equal, negative if 'x' is less than 'y' and positive if 'x' is greater than 'y'</returns>
		public int Compare(object x, object y)
		{
			int compareResult;
			ListViewItem listviewX, listviewY;

			// Cast the objects to be compared to ListViewItem objects
			listviewX = (ListViewItem)x;
			listviewY = (ListViewItem)y;
			//MP3.dprintf("ColumnToSort "+ ColumnToSort);
			// Compare the two items
			compareResult = ObjectCompare.Compare(listviewX.SubItems[ColumnToSort].Text,listviewY.SubItems[ColumnToSort].Text);

			// Calculate correct return value based on object comparison
			if (OrderOfSort == SortOrder.Ascending)
			{
				// Ascending sort is selected, return normal result of compare operation
				return compareResult;
			}
			else if (OrderOfSort == SortOrder.Descending)
			{
				// Descending sort is selected, return negative result of compare operation
				return (-compareResult);
			}
			else
			{
				// Return '0' to indicate they are equal
				return 0;
			}
		}
		
		/// <summary>
		/// Gets or sets the number of the column to which to apply the sorting operation (Defaults to '0').
		/// </summary>
		public int SortColumn
		{
			set
			{
				ColumnToSort = value;
			}
			get
			{
				return ColumnToSort;
			}
		}

		/// <summary>
		/// Gets or sets the order of sorting to apply (for example, 'Ascending' or 'Descending').
		/// </summary>
		public SortOrder Order
		{
			set
			{
				OrderOfSort = value;
			}
			get
			{
				return OrderOfSort;
			}
		}
		
	}
}
