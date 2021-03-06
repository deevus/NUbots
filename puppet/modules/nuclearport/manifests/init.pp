# == Class: nuclearport
#
# Clones and builds NUClearPort in the specified directory as the specified user
#
class nuclearport(
    $username = 'nubot',
    $nubots_dir = "/home/${username}/NUbots", #"
  ) {
  $nuclearport_build_dir = "${nubots_dir}/NUClearPort/build"

  vcsrepo { 'nuclearport_repo':
    require => [File["${nubots_dir}"], Package['git']],
    path => "${nubots_dir}/NUClearPort",
    source => "https://github.com/nubots/NUClearPort.git",
    provider => 'git',
    ensure => present,
    user => $username,
    owner => $username,
  } ->
  file { 'nuclearport_build_dir':
    path => $nuclearport_build_dir,
    ensure => directory,
    purge => true,
    force => true,
    owner => $username,
    group => $username,
  } ~>
  exec { 'nuclearport_cmake':
    require => [
        Class['nuclearport::build_dep'],
      ],
    command => 'cmake ..',
    cwd => $nuclearport_build_dir,
    path => $path,
    refreshonly => true,
    logoutput => "on_failure",
    user => $username,
  } ~>
  exec { 'nuclearport_make':
    command => 'make -j',
    cwd => $nuclearport_build_dir,
    path => $path,
    refreshonly => true,
    logoutput => "on_failure",
    user => $username,
  }
}

