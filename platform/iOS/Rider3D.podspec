Pod::Spec.new do |s|
  s.name         = 'Rider3D'
  s.version      = '1.0.0'
  s.summary      = 'A light 3d engine.'
  s.homepage     = 'https://gitee.com/scave/Rider3D'
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { 'Scave' => 'iscave@163.com' }
  s.source       = { :git => 'https://gitee.com/scave/Rider3D.git', :tag => s.version.to_s }
  s.platform     = :ios, '9.0'
  s.source_files = 'Rider3D/Rider3D/**/*'
  s.vendored_libraries = 'Rider3D/rider3d.a'
end
