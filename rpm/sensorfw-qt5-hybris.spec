# 
# Do NOT Edit the Auto-generated Part!
# Generated by: spectacle version 0.27
# 

Name:       hybris-libsensorfw-qt5

# >> macros
# << macros

Summary:    Sensor Framework Qt5
Version:    0.7.3.13
Release:    0
Group:      System/Sensor Framework
License:    LGPLv2+
URL:        http://gitorious.org/sensorfw
Source0:    %{name}-%{version}.tar.bz2
Source100:  sensorfw-qt5-hybris.yaml
Requires:   qt5-qtcore
Requires:   GConf-dbus
Requires:   %{name}-configs
Requires:   systemd
Requires:   sensord-qt5
Requires(preun): systemd
Requires(post): /sbin/ldconfig
Requires(post): systemd
Requires(postun): /sbin/ldconfig
Requires(postun): systemd
Requires: libhybris
Requires: libhybris-libhardware
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5DBus)
BuildRequires:  pkgconfig(Qt5Network)
BuildRequires:  pkgconfig(Qt5Test)
BuildRequires:  pkgconfig(gconf-2.0)
BuildRequires:  pkgconfig(sensord-qt5)
BuildRequires:  pkgconfig(libhardware)
BuildRequires:  pkgconfig(android-headers)

%description
Sensor Framework provides an interface to hardware sensor drivers through logical sensors. This package contains sensor framework daemon and required libraries.

%package devel
Summary:    Sensor framework daemon libraries development headers
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}
Requires:   qt5-qtcore-devel
Requires:   qt5-qtdbus-devel
Requires:   qt5-qtnetwork-devel

%description devel
Development headers for sensor framework daemon and libraries.


%package configs
Summary:    Sensorfw configuration files
Group:      System/Libraries
BuildArch:  noarch
Requires:   %{name} = %{version}
Provides:   config-hybris

%description configs
Sensorfw configuration files.

%prep
%setup -q -n %{name}-%{version}

# >> setup
# << setup

%build
unset LD_AS_NEEDED
# >> build pre
export LD_RUN_PATH=/usr/lib/sensord/
export QT_SELECT=5
# << build pre

%qmake5 CONFIG+=hybris

make %{?jobs:-j%jobs}

# >> build post
# << build post

%install
rm -rf %{buildroot}
# >> install pre
export QT_SELECT=5
# << install pre
%qmake5_install

# >> install post
# << install post

%preun
if [ "$1" -eq 0 ]; then
systemctl stop sensord.service
fi

%post
/sbin/ldconfig
systemctl daemon-reload
systemctl reload-or-try-restart sensord.service

%postun
/sbin/ldconfig
systemctl daemon-reload

%files
%defattr(-,root,root,-)
# >> files
%{_libdir}/libhybrissensorfw*.so.*
%{_libdir}/libhybrissensorfw*.so
%{_libdir}/sensord-qt5/*.so
# << files

%files devel
%defattr(-,root,root,-)
# >> files devel
%{_includedir}/sensord-qt5/*
# << files devel

%files configs
%defattr(-,root,root,-)
# >> files configs
%config %{_sysconfdir}/sensorfw/sensord-hybris.conf
# << files configs
