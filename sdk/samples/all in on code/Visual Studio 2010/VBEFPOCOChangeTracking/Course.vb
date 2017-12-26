'------------------------------------------------------------------------------
' <auto-generated>
'     This code was generated from a template.
'
'     Changes to this file may cause incorrect behavior and will be lost if
'     the code is regenerated.
' </auto-generated>
'------------------------------------------------------------------------------
Imports System
Imports System.Collections
Imports System.Collections.Generic
Imports System.Collections.ObjectModel
Imports System.Collections.Specialized

Partial Public Class Course
    #Region "Primitive Properties"

    Public Overridable Property CourseID As Integer

    Public Overridable Property Title As String

    Public Overridable Property Credits As Nullable(Of Integer)

    Public Overridable Property DepartmentID As Nullable(Of Integer)
        Get
            Return _departmentID
        End Get
        Set(ByVal value As Nullable(Of Integer))
            Try
                _settingFK = True
                If Not Equals (_departmentID, value) Then
                    If Department IsNot Nothing AndAlso Not Equals(Department.DepartmentID, value) Then
                        Department = Nothing
                    End If
                    _departmentID = value
                End If
            Finally
                _settingFK = False
            End Try
        End Set
    End Property
    Private _departmentID As Nullable(Of Integer)

    Public Overridable Property StatusID As Nullable(Of Boolean)

    #End Region
    #Region "Navigation Properties"

    Public Overridable Property Department As Department
        Get
            Return _department
        End Get
        Set(ByVal value As Department)
            If _department IsNot value Then
                Dim previousValue As Department = _department
                _department = value
                FixupDepartment(previousValue)
            End If
        End Set
    End Property
    Private _department As Department

    #End Region
    #Region "Association Fixup"
    Private _settingFK As Boolean = False

    Private Sub FixupDepartment(ByVal previousValue As Department)
        If previousValue IsNot Nothing AndAlso previousValue.Courses.Contains(Me) Then
            previousValue.Courses.Remove(Me)
        End If
        If Department IsNot Nothing Then
            If Not Department.Courses.Contains(Me) Then
                Department.Courses.Add(Me)
            End If
            If Not Equals(DepartmentID, Department.DepartmentID) Then
                DepartmentID = Department.DepartmentID
            End If
        ElseIf Not _settingFK Then
            DepartmentID = Nothing
        End If
    End Sub

    #End Region
End Class